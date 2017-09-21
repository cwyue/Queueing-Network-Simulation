/*
 * random_number.c
 *
 *  Created on: 2016Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random_number.h"

double urand(void){//generate a random value in (0,1]
	return rand()/(RAND_MAX+1.0);
}
double random(double mean){
	return -mean*(log(1-urand()));
}


