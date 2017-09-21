/*
 * event_handler.h
 *
 *  Created on: Sep 29, 2016
 *      Author: yychu
 */
#ifndef SRC_EVENT_HANDLER_H_
#define SRC_EVENT_HANDLER_H_

/*
 *Define external variables for event handlers.
 */
extern int end_time;
extern double mean_servicetime;
extern double mean_intertime;
extern double current_time;
extern int num_parts;
extern double total_time;
extern double total_waiting_time;
extern int num_station1;
extern int num_station2;
extern int num_station3;

/** @brief handle the arrival event, schedule corresponde event
 *         and update QueueA for station A.
 *
 *  @param event The event object trigger this handler
 *  @param eventlist The Piority queue contains all events 
 *  @param queueA The FIFO queue for staion A storing the parts
 *  @return Void.
 */
void arrival(PEVENT event,PEL eventlist,PQUEUE queueA);

/** @brief handle the departstation1 event, schedule corresponde event
 *         and update QueueB and QueueA for station A and B.
 *
 *  @param event The event object trigger this handler
 *  @param eventlist The Piority queue contains all events 
 *  @param queueA The FIFO queue for station A storing the parts
 *  @param queueB The FIFO queue for station B storing the parts
 *  @return Void.
 */
void departStation1(PEVENT event,PEL eventlist,PQUEUE queueA,PQUEUE queueB);

/** @brief handle the departstation2 event, schedule corresponde event
 *         and update QueueB and QueueC for station C and B.
 *
 *  @param event The event object trigger this handler
 *  @param eventlist The Piority queue contains all events 
 *  @param queueA The FIFO queue for station B storing the parts
 *  @param queueB The FIFO queue for station C storing the parts
 *  @return Void.
 */
void departStation2(PEVENT event,PEL eventlist,PQUEUE queueB,PQUEUE queueC);

/** @brief handle the departstation1 event, schedule corresponde event
 *         and update QueueC for C.
 *         This function will also update total_time and wait_time
 *
 *  @param event The event object trigger this handler
 *  @param eventlist The Piority queue contains all events 
 *  @param queueC The FIFO queue for station A storing the parts
 *  @return Void.
 */
void departStation3(PEVENT event,PEL eventlist,PQUEUE queueC);

/** @brief Print the state of the system including the piority
 *         queue, the FIFO queue and all the other information
 *
 *  @param cevent The current event
 *  @param pQ The Piority queue contains all events 
 *  @param num_station1 the number of parts in station 1
 *  @param num_station2 the number of parts in station 2
 *  @param num_station3 the number of parts in station 3
 *  @return Void.
 */
void printList(PEL pQ,PEVENT cevent,int num_station1,int num_station2,int num_station3);

#endif /* SRC_EVENT_HANDLER_H_ */
