/*
 * main.c
 *
 *  Created on: 2016��9��29��
 *      Author: Administrator
 */
#include "event_list.h"
#include "part_queue.h"
#include "random_number.h"
#include "event_handler.h"
#include "simulation_engine.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int end_time = 10000;
double mean_servicetime = 10;
double mean_intertime = 10;

int main(void) {
	srand(time(0));
	major_simulation();
}





