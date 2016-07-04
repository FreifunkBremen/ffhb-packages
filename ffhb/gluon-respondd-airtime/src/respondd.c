#include <string.h>
#include <stdio.h>

#include <json-c/json.h>

#include <respondd.h>

#include "airtime.h"

void fill_airtime_json(struct airtime_result *air, struct json_object* wireless){
	struct json_object *ret = NULL, *obj = NULL;

	obj = json_object_new_object();
	if(!obj)
		goto error;

	ret = json_object_new_int64(air->active_time.current);
	if(!ret)
		goto error;
	json_object_object_add(obj,"active",ret);

	ret = json_object_new_int64(air->busy_time.current);
	if(!ret)
		goto error;
	json_object_object_add(obj,"busy",ret);

	ret = json_object_new_int64(air->rx_time.current);
	if(!ret)
		goto error;
	json_object_object_add(obj,"rx",ret);

	ret = json_object_new_int64(air->tx_time.current);
	if(!ret)
		goto error;
	json_object_object_add(obj,"tx",ret);

	ret = json_object_new_int(air->noise);
	if(!ret)
		goto error;
	json_object_object_add(obj,"noise",ret);

	ret = json_object_new_int(air->frequency);
	if(!ret)
		goto error;
	json_object_object_add(obj,"frequency",ret);

error:
	if(air->frequency >= 2400  && air->frequency < 2500)
		json_object_object_add(wireless, "airtime24", obj);
	else if (air->frequency >= 5000 && air->frequency < 6000)
		json_object_object_add(wireless, "airtime5", obj);
}

static struct json_object *respondd_provider_statistics(void) {
	struct airtime *a = NULL;
	struct json_object *ret = NULL, *wireless = NULL;

	wireless = json_object_new_object();
	if (!wireless)
		return NULL;

	ret = json_object_new_object();
	if (!ret)
		return NULL;

	a = get_airtime("client0","client1");
	if (!a)
		goto end;


	if (!a->radio0.frequency)
		goto end;
	fill_airtime_json(&a->radio0,wireless);

	if (!a->radio1.frequency)
		goto end;
	fill_airtime_json(&a->radio1,wireless);

end:
	json_object_object_add(ret, "wireless", wireless);
	return ret;
}

const struct respondd_provider_info respondd_providers[] = {
	{"statistics", respondd_provider_statistics},
	{0, 0},
};
