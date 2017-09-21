/*
 * event_handler.c
 *
 *  Created on: Sep 29, 2016
 *      Author: yychu
 */

#include <stdio.h>
#include <stdlib.h>
#include "event_list.h"
#include "part_queue.h"
#include "random_number.h"
#include "event_handler.h"
#include <time.h>
#include <math.h>


double current_time;
int num_parts;
double total_time;
double total_waiting_time;
int num_station1;
int num_station2;
int num_station3;

void arrival(PEVENT event,PEL eventlist,PQUEUE queueA){
	PPART currentpart = pop_part(queueA);
	double service_time = currentpart->service_time;
	double timestamp = 0;
	num_station1++;
	//check if station1 is free
	if (num_station1 == 1){
		timestamp = current_time+service_time;
		add_event(eventlist,2,timestamp);
	}
	//schedule next arrival event
	service_time = random(mean_servicetime);
	double inter_time = random(mean_intertime);
	add_parts(queueA,service_time,current_time+inter_time);
	add_event(eventlist,1,current_time+inter_time);
}


void departStation1(PEVENT event,PEL eventlist,PQUEUE queueA,PQUEUE queueB){
	// handle current part
	PPART current_part = pop_part(queueA);
	num_station1--;
	num_station2++;
	double service_time = current_part->service_time;
	double generate_time = current_part->generate;
	add_parts(queueB,service_time,generate_time);
	delete_parts(queueA);
	//check if station2 is free
	if(num_station2 == 1) {
		add_event(eventlist,3,current_time+service_time);
	}
	// schedule next departure for part in queueA
	if(num_station1 > 0) {
		current_part = pop_part(queueA);
		service_time = current_part->service_time;
		generate_time = current_part->generate;
		add_event(eventlist,2,current_time+service_time);
	}
}

void departStation2(PEVENT event,PEL eventlist,PQUEUE queueB,PQUEUE queueC){

	// handle current part
	PPART current_part = pop_part(queueB);
	num_station2--;
	num_station3++;
	double service_time = current_part->service_time;
	double generate_time = current_part->generate;
	add_parts(queueC,service_time,generate_time);
	delete_parts(queueB);
	//check if station3 is free
	if(num_station3 == 1) {
		add_event(eventlist,4,current_time+service_time);
	}
	// schedule next departure for part in queueA
	if(num_station2 > 0) {
		current_part = pop_part(queueB);
		service_time = current_part->service_time;
		generate_time = current_part->generate;
		add_event(eventlist,3,current_time+service_time);
	}
}

void departStation3(PEVENT event,PEL eventlist,PQUEUE queueC ){
	// handle current part
	PPART current_part = pop_part(queueC);
	num_station3--;
	double depart_time = current_time;
	double generate_time = current_part->generate;
	double service_time = current_part->service_time;
	// update two output values
	total_time = total_time + depart_time - generate_time;
	total_waiting_time  = total_waiting_time + depart_time - generate_time - service_time*3;
	num_parts++;
	delete_parts(queueC);
	//schedule next depart
	if(num_station3 > 0) {
		current_part = pop_part(queueC);
		service_time = current_part->service_time;
		generate_time = current_part->generate;
		add_event(eventlist,4,current_time+service_time);
	}
}

void printList(PEL pQ,PEVENT cevent,int num_station1,int num_station2,int num_station3){
	printf("Current Event: event type: %d, time: %f\n",cevent->type,cevent->time);
	PEVENT current = pQ->pFirst->pNext;
	printf("Current_time = %f",current_time);
	printf(",and current queue size for each station A=%d B=%d C=%d\n",num_station1,num_station2,num_station3);
	printf("Current eventlist is:\n");
	while(current != NULL){
		printf("event type: %d, time: %f\n",current->type, current->time);
		current = current->pNext;
	}
	printf("\n");
}

