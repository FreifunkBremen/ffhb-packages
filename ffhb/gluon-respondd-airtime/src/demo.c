#include <stdio.h>

#include "airtime.h"

void print_result(struct airtime_result *);

int main() {
	struct airtime *a = get_airtime();

	print_result(&a->radio24);
	print_result(&a->radio5);
}

void print_result(struct airtime_result *result){
	printf("freq=%d\tbusy=%lld\tactive=%lld\tnoise=%d\n", result->frequency, result->busy_time, result->active_time, result->noise);
}
