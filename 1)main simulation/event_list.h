/*
 * event_list.h
 *
 *  Created on: 2016Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */

#ifndef EVENT_LIST_H_
#define EVENT_LIST_H_

/*
 * The structure to store event info
 */
typedef struct event{
	double time;
	int type;
	struct event * pNext;
}EVENT,* PEVENT;

/*
 * The structure to realize piority queue
 */
typedef struct eventList{
	PEVENT pFirst;
}EL, *PEL;

/** @brief initialize the part queue
 *  
 *  @param pList the queue needs to be initialized 
 *  @return void
 */
void init_eList(PEL pList);

/** @brief add a event to the queue
 *  
 *  @param pList the queue needs to be added a event
 *  @type type of event
 *  @time the timestamp 
 *  @return void
 */
void add_event(PEL pList,int type,double time);

/** @pop the top parts of the queue
 *  
 *  @param pList the resouse queue
 *  @return poped event object
 */
PEVENT pop_event(PEL pList);

/** @delete the top parts of the queue
 *  
 *  @param pList the resouse queue
 *  @return void
 */
void delete_event(PEL pList);

/** @free the whole queue
 *  
 *  @param pList the resource queue
 *  @return void
 */
void free_eventlist(PEL pList);


#endif /* EVENT_LIST_H_ */
