#pragma once

extern const double INVALID_AIRTIME;

struct airtime {
	double a24;
	double a5;
};

struct airtime *get_airtime(void);

#define DEBUG { printf("Reached %s:%d\n", __FILE__, __LINE__); fflush(NULL); }
