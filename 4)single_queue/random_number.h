/*
 * random_number.h
 *
 *  Created on: 2016Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */

#ifndef RANDOM_NUMBER_H_
#define RANDOM_NUMBER_H_

/** @brief generate the random number follow uniform distribution in (0,1]
 *  @return a random number.
 */
double urand(void);

/** @brief generate the random number follow exponential distribution with certai mean
 *  
 *  @param mean the mean of distribution 
 *  @return a random number.
 */
double random(double mean);

#endif /* RANDOM_NUMBER_H_ */
