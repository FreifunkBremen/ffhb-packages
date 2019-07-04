#include <respondd.h>
#include <json-c/json.h>

#include <net/if.h>
#include <netlink/netlink.h>
#include <netlink/genl/genl.h>
#include <arpa/inet.h>
#include <linux/if_addr.h>
#include <linux/rtnetlink.h>


struct ip_address_information {
	struct json_object *addresses;
};

static int get_addresses_cb(struct nl_msg *msg, void *arg) {
	struct ip_address_information *info = (struct ip_address_information*) arg;

	struct nlmsghdr *nlh = nlmsg_hdr(msg);
	struct ifaddrmsg *msg_content = NLMSG_DATA(nlh);
	int remaining = nlh->nlmsg_len - NLMSG_LENGTH(sizeof(struct ifaddrmsg));
	struct rtattr *hdr;

	for (hdr = IFA_RTA(msg_content); RTA_OK(hdr, remaining); hdr = RTA_NEXT(hdr, remaining)) {
		char addr_str_buf[INET6_ADDRSTRLEN];

		if (hdr->rta_type != IFA_ADDRESS ||
/*			msg_content->ifa_index != info->ifindex ||*/
			msg_content->ifa_flags & (IFA_F_TENTATIVE|IFA_F_DEPRECATED)) {
			continue;
		}

		if (inet_ntop(AF_INET6, (struct in6_addr *) RTA_DATA(hdr), addr_str_buf, INET6_ADDRSTRLEN)) {
			json_object_array_add(info->addresses, json_object_new_string(addr_str_buf));
		}
	}

	return NL_OK;
}

static void add_all_addresses_to_array (struct json_object* result_array)
{
	struct ip_address_information info = {
		.addresses = result_array,
	};
	int err;

	/* Open socket */
	struct nl_sock *socket = nl_socket_alloc();
	if (!socket) {
		return;
	}

	err = nl_connect(socket, NETLINK_ROUTE);
	if (err < 0) {
		goto out_free;
	}

	/* Send message */
	struct ifaddrmsg rt_hdr = { .ifa_family = AF_INET6, };
	err = nl_send_simple(socket, RTM_GETADDR, NLM_F_REQUEST | NLM_F_ROOT, &rt_hdr, sizeof(struct ifaddrmsg));
	if (err < 0) {
		goto out_free;
	}

	/* Retrieve answer. Message is handled by get_addresses_cb */
	nl_socket_modify_cb(socket, NL_CB_VALID, NL_CB_CUSTOM, get_addresses_cb, &info);
	nl_recvmsgs_default(socket);

out_free:
	nl_socket_free(socket);
}

static struct json_object * respondd_provider_nodeinfo(void) {
    struct json_object *ret, *ret_network, *ret_addresses;

    ret_addresses = json_object_new_array();
    add_all_addresses_to_array(ret_addresses);

    ret_network = json_object_new_object();
    json_object_object_add(ret_network, "addresses", ret_addresses);

    ret = json_object_new_object();
    json_object_object_add(ret, "network", ret_network);
    return ret;
}

const struct respondd_provider_info respondd_providers[] = {
    {"nodeinfo", respondd_provider_nodeinfo},
    {}
};
