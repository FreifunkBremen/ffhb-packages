#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

#include <json-c/json.h>
#include <uci.h>

#include <respondd.h>


const unsigned int INVALID_CHANNEL = 0;
const unsigned int INVALID_TXPOWER = 0;

static const char const *wifi_24_dev = "radio0";
static const char const *wifi_50_dev = "radio1";

static inline const char *lookup_option_value(struct uci_context *ctx, struct uci_package *p, const char *section_name, const char *option_name) {

	struct uci_section *s = uci_lookup_section(ctx, p, section_name);
	if (!s)
		return NULL;
	return uci_lookup_option_string(ctx, s, option_name);
}

static inline unsigned char parse_option(const char *s, unsigned char invalid) {
	char *endptr = NULL;
	long int result;

	if (!s)
		return invalid;

	result = strtol(s, &endptr, 10);

	if (!endptr)
		return invalid;
	if ('\0' != *endptr)
		return invalid;
	if (result > UCHAR_MAX)
		return invalid;
	if (result < 0)
		return invalid;

	return (unsigned char)(result % UCHAR_MAX);
}

static inline unsigned char parse_channel(const char *s) {
	return parse_option(s, INVALID_CHANNEL);
}

static inline unsigned char parse_txpower(const char *s) {
	return parse_option(s, INVALID_TXPOWER);
}

static struct json_object *respondd_provider_nodeinfo(void) {
	struct uci_package *p = NULL;
	struct uci_context *ctx = NULL;
	struct json_object *ret = NULL, *wireless = NULL;

	ctx = uci_alloc_context();
	if (!ctx)
		goto end;
	ctx->flags &= ~UCI_FLAG_STRICT;

	if (uci_load(ctx, "wireless", &p))
		goto end;

	wireless = json_object_new_object();
	if (!wireless)
		goto end;

	ret = json_object_new_object();
	if (!ret)
		goto end;

	unsigned char tmp;
	struct json_object *v;

	tmp = parse_channel(lookup_option_value(ctx, p, wifi_24_dev, "channel"));
	if (tmp != INVALID_CHANNEL) {
		v = json_object_new_int64(tmp);
		if (!v)
			goto end;
		json_object_object_add(wireless, "chan2", v);
	}
	tmp = parse_channel(lookup_option_value(ctx, p, wifi_50_dev, "channel"));
	if (tmp != INVALID_CHANNEL) {
		v = json_object_new_int64(tmp);
		if (!v)
			goto end;
		json_object_object_add(wireless, "chan5", v);
	}
	tmp = parse_channel(lookup_option_value(ctx, p, wifi_24_dev, "txpower"));
	if (tmp != INVALID_TXPOWER) {
		v = json_object_new_int64(tmp);
		if (!v)
			goto end;
		json_object_object_add(wireless, "txpower2", v);
	}
	tmp = parse_channel(lookup_option_value(ctx, p, wifi_50_dev, "txpower"));
	if (tmp != INVALID_TXPOWER) {
		v = json_object_new_int64(tmp);
		if (!v)
			goto end;
		json_object_object_add(wireless, "txpower5", v);
	}

	json_object_object_add(ret, "wireless", wireless);
end:
	if (ctx) {
		if (p)
			uci_unload(ctx, p);
			uci_free_context(ctx);
	}
	return ret;

}

const struct respondd_provider_info respondd_providers[] = {
	{"nodeinfo", respondd_provider_nodeinfo},
	{0},
};
