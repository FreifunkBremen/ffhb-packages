#include <string.h>
#include <stdio.h>

#include <json-c/json.h>

#include <respondd.h>

#include "airtime.h"

/* FIXME error handling */
static struct json_object *respondd_provider_statistics(void) {
	struct airtime *a = NULL;
	struct json_object *ret = NULL, *wireless = NULL;

	wireless = json_object_new_object();
	if (!wireless)
		goto end;

	ret = json_object_new_object();
	if (!ret)
		goto end;

	a = get_airtime();
	if (!a)
		return NULL;

	struct json_object *v;

	if (a->a24 != INVALID_AIRTIME) {
		v = json_object_new_double(a->a24);
		if (!v)
			goto end;
		json_object_object_add(wireless, "airtime24", v);
	}
	if (a->a5 != INVALID_AIRTIME) {
		v = json_object_new_double(a->a5);
		if (!v)
			goto end;
		json_object_object_add(wireless, "airtime5", v);
	}

	json_object_object_add(ret, "wireless", wireless);

end:
	free(a);
	return ret;
}

const struct respondd_provider_info respondd_providers[] = {
	{"statistics", respondd_provider_statistics},
	{0, 0},
};
