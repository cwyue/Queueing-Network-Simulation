/*
 * simulaiton_engine.c
 *
 *  Created on: 2016Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include "event_list.h"
#include "part_queue.h"
#include "random_number.h"
#include "simulation_engine.h"
#include "event_handler.h"
#include <time.h>
#include <math.h>

double major_simulation(){
	EL Eventlist;
	QUEUE QueueA;
	QUEUE QueueB;
	QUEUE QueueC;
	PEL eventlist = &Eventlist;
	PQUEUE queueA = &QueueA;
	PQUEUE queueB = &QueueB;
	PQUEUE queueC = &QueueC;

	current_time = 0.0;
	num_parts = 0;
	total_time = 0.0;
	total_waiting_time = 0.0;
	num_station1 = 0;
	num_station2 = 0;
	num_station3 = 0;


	init_eList(eventlist);
	init_queue(queueA);
	init_queue(queueB);
	init_queue(queueC);

	//generate first part
	double service_time = random(mean_servicetime);
	add_parts(queueA,service_time,current_time);
	add_event(eventlist,1,current_time);
	while (current_time < end_time){
		PEVENT currentevent = pop_event(eventlist);
		current_time = currentevent->time;
		//printList(eventlist,currentevent,num_station1,num_station2,num_station3);
		switch(currentevent->type){
			case 1:
			arrival(currentevent,eventlist,queueA);
			break;
			case 2:
			departStation1(currentevent,eventlist,queueA,queueB);
			break;
			case 3:
			departStation2(currentevent,eventlist,queueB,queueC);
			break;
			case 4:
			departStation3(currentevent,eventlist,queueC);
			break;
		}
		delete_event(eventlist);
	}
	free_eventlist(eventlist);
	free_partqueue(queueA);
	free_partqueue(queueB);
	free_partqueue(queueC);
	printf("Arrival rate = %f ,Average time in system = %f, Average queuing delay = %f \n",1/mean_intertime,total_time/num_parts,total_waiting_time/num_parts);
	return total_waiting_time/num_parts;
}



