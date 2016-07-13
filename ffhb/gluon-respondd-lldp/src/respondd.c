#include <respondd.h>
#include <json-c/json.h>
#include <lldpctl.h>
#include <lldp-const.h>

static struct json_object * respondd_provider_neighbours(void) {
    lldpctl_conn_t *conn;
    lldpctl_atom_t *ifaces, *iface, *port, *neighbors, *neighbor;
    const char *neighmac, *portmac, *sysname, *sysdescr;
    struct json_object *ret, *ret_lldp, *neighbors_obj, *neighbor_obj;


    conn = lldpctl_new(NULL, NULL, NULL);

    if(!conn)
        return NULL;

    ifaces   = lldpctl_get_interfaces(conn);
    ret_lldp = json_object_new_object();
    lldpctl_atom_foreach(ifaces, iface) {
        port = lldpctl_get_port(iface);
        // check if Port ID Subtype is MAC address
        if (lldpctl_atom_get_int(port, lldpctl_k_port_id_subtype) != LLDP_PORTID_SUBTYPE_LLADDR)
            continue;

        portmac = lldpctl_atom_get_str(port, lldpctl_k_port_id);
        if (!portmac)
            continue;

        neighbors_obj = json_object_new_object();
        neighbors = lldpctl_atom_get(port, lldpctl_k_port_neighbors);
        lldpctl_atom_foreach(neighbors, neighbor) {
            // check if Chassis ID Subtype is MAC address
            if (lldpctl_atom_get_int(neighbor, lldpctl_k_chassis_id_subtype) != LLDP_CHASSISID_SUBTYPE_LLADDR)
                continue;

            neighmac = lldpctl_atom_get_str(neighbor, lldpctl_k_chassis_id);
            if (!neighmac)
                continue;

            neighbor_obj = json_object_new_object();
            sysname  = lldpctl_atom_get_str(neighbor, lldpctl_k_chassis_name);
            sysdescr = lldpctl_atom_get_str(neighbor, lldpctl_k_chassis_descr);

            if (sysname)
                json_object_object_add(neighbor_obj, "name", json_object_new_string(sysname));
            if (sysdescr)
                json_object_object_add(neighbor_obj, "descr", json_object_new_string(sysdescr));

            json_object_object_add(neighbors_obj, neighmac, neighbor_obj);
        }
        json_object_object_add(ret_lldp, portmac, neighbors_obj);
    }

    lldpctl_release(conn);

    ret = json_object_new_object();
    json_object_object_add(ret, "lldp", ret_lldp);
    return ret;
}

const struct respondd_provider_info respondd_providers[] = {
    {"neighbours", respondd_provider_neighbours},
    {}
};
