/*
 * random_number.c
 *
 *  Created on: 2016��9��29��
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random_number.h"

double urand(void){
	return rand()/(RAND_MAX+1.0);
}
double random(double mean){
	return -mean*(log(1-urand()));
}


