#include <stdio.h>
#include <signal.h>
#include <unistd.h> /* sleep */
#include <string.h> /* memset */

#include "airtime.h"

void print_result(struct airtime_result *);


static volatile int keepRunning = 1;

void intHandler(int dummy) {
    keepRunning = 0;
}

int main() {
	signal(SIGINT, intHandler);
	struct airtime a;
	memset(&a, 0, sizeof(a));

	while (keepRunning) {
		get_airtime(&a);
		print_result(&a.radio24);
		print_result(&a.radio5);
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
