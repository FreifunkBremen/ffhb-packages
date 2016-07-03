#include <string.h>
#include <stdio.h>

#include <json-c/json.h>

#include <respondd.h>

#include "airtime.h"

void fill_airtime_json(struct airtime_result air, struct json_object *obj){
	struct json_object *ret = NULL;
	ret = json_object_new_int64(air.active_time.current);
	if(ret)
		json_object_object_add(obj,"busy_time",ret);

	ret = json_object_new_int64(air.busy_time.current);
	if(ret)
		json_object_object_add(obj,"busy_time",ret);

	ret = json_object_new_int64(air.rx_time.current);
	if(ret)
		json_object_object_add(obj,"rx_time",ret);

	ret = json_object_new_int64(air.tx_time.current);
	if(ret)
		json_object_object_add(obj,"tx_time",ret);

	ret = json_object_new_int(air.noise);
	if(ret)
		json_object_object_add(obj,"noise",ret);

	ret = json_object_new_int(air.frequency);
	if(ret)
		json_object_object_add(obj,"frequency",ret);
}

static struct json_object *respondd_provider_statistics(void) {
	struct airtime *a = NULL;
	struct json_object *ret = NULL, *wireless = NULL;

	wireless = json_object_new_object();
	if (!wireless)
		goto end;

	ret = json_object_new_object();
	if (!ret)
		goto end;

	a = get_airtime("client0","client1");
	if (!a)
		return NULL;

	struct json_object *v = NULL;

	fill_airtime_json(a->radio0,v);
	if (!v)
		goto end;
	json_object_object_add(wireless, "airtime24", v);

	fill_airtime_json(a->radio1,v);
	if (!v)
		goto end;
	json_object_object_add(wireless, "airtime5", v);

	json_object_object_add(ret, "wireless", wireless);

end:
	free(a);
	return ret;
}

const struct respondd_provider_info respondd_providers[] = {
	{"statistics", respondd_provider_statistics},
	{0, 0},
};
