#include <stdio.h>
#include <unistd.h> /* sleep */

#include "airtime.h"

void print_result(struct airtime_result *);

int main() {
	struct airtime *a;

	while (1) {
		a = get_airtime();
		print_result(&a->radio24);
		print_result(&a->radio5);
		sleep(1);
	}
}

void print_result(struct airtime_result *result){
	printf("freq=%d\tnoise=%d\tbusy=%lld\tactive=%lld\trx=%lld\ttx=%lld\n",
		result->frequency,
		result->noise,
		result->busy_time.current,
		result->active_time.current,
		result->rx_time.current,
		result->tx_time.current
	);
}
