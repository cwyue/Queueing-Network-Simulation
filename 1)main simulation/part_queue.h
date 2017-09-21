/*
 * part_queue.h
 *
 *  Created on: 2016Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */

#ifndef PART_QUEUE_H_
#define PART_QUEUE_H_

typedef struct part{
	double service_time;
	double generate;
	struct part* pBefore;
}PART,*PPART;

typedef struct parts_queue{
	PPART pTail;
}QUEUE,*PQUEUE;

void init_queue(PQUEUE pQ);
void add_parts(PQUEUE pQ,double serve,double generate);
void delete_parts(PQUEUE pQ);
PPART pop_part(PQUEUE pQ);
void free_partqueue(PQUEUE pQ);


#endif /* PART_QUEUE_H_ */
