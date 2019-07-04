#include <respondd.h>
#include <json-c/json.h>

static struct json_object * respondd_provider_neighbours(void) {
    struct json_object *ret, *ret_network, *ret_addresses;

    ret_addresses = json_object_new_array();
    json_object_array_add(ret_addresses, "1.2.3.4");

    ret_network = json_object_new_object();
    json_object_object_add(ret_network, "addresses", ret_addresses);

    ret = json_object_new_object();
    json_object_object_add(ret, "network", ret_network);
    return ret;
}

const struct respondd_provider_info respondd_providers[] = {
    {"neighbours", respondd_provider_neighbours},
    {}
};
