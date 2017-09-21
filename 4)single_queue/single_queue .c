#include "event_list.h"
#include "part_queue.h"
#include "random_number.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double queue_simulation();
QUEUE QueueA;
PQUEUE queueA = &QueueA;
double arrive_interval = 10;
double service_mean = 6;

int main(void){
	srand(time(0));
	double wait_sum = 0;
	for(int i=1;i<2000;i++)
	{
		double temp = queue_simulation();
		wait_sum = wait_sum+temp;
		printf("After %dth iteration, the average of average queuing delay = %f \n",i,wait_sum/i);
	}
	printf("arrive_interval_mean = %f service_time_mean = %f\n",arrive_interval,service_mean);
	free_partqueue(queueA);
	return wait_sum;
}


double queue_simulation(){

	double time = 0;
	int end_time = 10000;

	double waiting_time = 0;

	double t1 = 0; //arrival time
	double t2 = 1; //departure time
	int num_inqueue = 0; // number of parts in queue
	int num_finish = 0;

	PPART current_part;
	init_queue(queueA);
	while(time < end_time) {
		if(t1 < t2 ) // check the piority of two events
		{
			time = t1; 
			t1 = t1+random(arrive_interval); // update arrival event
			double service_time = random(service_mean);
			add_parts(queueA,service_time,t1);
			num_inqueue++;
			// check if station is free
			if(num_inqueue == 1){
				current_part = pop_part(queueA);
				t2 = t1 + current_part->service_time;
			}
		}
		else {
			current_part = pop_part(queueA);
			time = t2;
			waiting_time = waiting_time + time - current_part->generate-current_part->service_time;
			num_finish++;
			delete_parts(queueA);
			num_inqueue--;
			// check if there is another part in queue
			if(num_inqueue>0) {
				PPART current_part = pop_part(queueA);
				if(current_part->generate > t2) {
					t2 = current_part->generate;
				}
				t2 = t2 + current_part->service_time;
			}
			else {
				// set the station to idle
				t2 = end_time+100;
			}
		}
	}
	return waiting_time/num_finish;
}




