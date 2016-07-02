#pragma once

#include <stdint.h>

struct airtime_result {
	uint32_t frequency;
	uint64_t active_time;
	uint64_t busy_time;
	uint64_t rx_time;
	uint64_t tx_time;
	uint8_t  noise;
};

struct airtime {
	struct airtime_result radio24;
	struct airtime_result radio5;
};

struct airtime *get_airtime(void);

#define DEBUG { printf("Reached %s:%d\n", __FILE__, __LINE__); fflush(NULL); }
