#include <respondd.h>
#include <json-c/json.h>

#include <net/if.h>
#include <netlink/netlink.h>
#include <netlink/route/link.h>
#include <netlink/route/addr.h>


static void add_all_addresses_to_array (struct json_object* result_array)
{
    struct nl_sock *sock = NULL;
    struct nl_cache *cache_link = NULL;
    struct nl_cache *cache_addr = NULL;
    int err = 0;

    if ((sock = nl_socket_alloc()) == NULL)
    {
        perror("nl_socket_alloc");
        goto end;
    }

    if ((err = nl_connect(sock, NETLINK_ROUTE)) < 0)
    {
        nl_perror(err, "nl_connect");
        goto end;
    }

    if ((err = rtnl_link_alloc_cache(sock, AF_UNSPEC, &cache_link)) < 0)
    {
        nl_perror(err, "rtnl_link_alloc_cache");
        goto end;
    }

    if ((err = rtnl_addr_alloc_cache(sock, &cache_addr)) < 0)
    {
        nl_perror(err, "rtnl_addr_alloc_cache");
        goto end;
    }

    {
        uint32_t flags;
        struct nl_object *item_link = nl_cache_get_first(cache_link);
        char ip_buf[BUFSIZ] = {0};
        int ifidx;

        for (; item_link; item_link = nl_cache_get_next(item_link))
        {
            struct nl_addr *ip_addr = NULL;
            struct rtnl_link *link = (struct rtnl_link *) item_link;
            flags = rtnl_link_get_flags(link);

            /* skip loopback interface */
            if (flags & IFF_LOOPBACK) continue;

            ifidx = rtnl_link_get_ifindex(link);
            {
                struct nl_object *item_addr = nl_cache_get_first(cache_addr);
                for (; item_addr; item_addr = nl_cache_get_next(item_addr))
                {
                    if (ifidx == rtnl_addr_get_ifindex((struct rtnl_addr *) item_addr))
                    {
                        ip_addr = rtnl_addr_get_local((struct rtnl_addr *) item_addr);
                        nl_addr2str(ip_addr, ip_buf, sizeof(ip_buf));
                        json_object_array_add(ret_addresses, json_object_new_string(ip_buf));
                    }
                }
            }
        }
    }

end:
    if (sock)
        nl_close(sock);
    if (cache_link)
        nl_cache_free(cache_link);
    if (cache_addr)
        nl_cache_free(cache_addr);
    if (sock)
        nl_socket_free(sock);
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
