/*
 * event_list.c

 *
 *  Created on: 2016Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include "event_list.h"
#include "part_queue.h"


void init_eList(PEL pList){//initialize an event list
	pList->pFirst=(PEVENT)malloc(sizeof(EVENT));
	if(pList->pFirst==NULL){
		exit(-1);
	}
	pList->pFirst->pNext=NULL;
}


void add_event(PEL pList,int type,double time){
	/*
	 * insert an event to the event list based on its timestamp
	 * here I use insert sort algorithm and sort them by ascending order
	 */
	PEVENT e=(PEVENT)malloc(sizeof(EVENT));
	if(e==NULL){
		exit(-1);
	}
	e->time=time;
	e->type = type;
	PEVENT p=pList->pFirst;
	PEVENT q=p->pNext;
	while(q!=NULL){
		if(e->time>=q->time){
			p=q;
			q=q->pNext;
		}else{
			break;
		}
	}
	e->pNext=q;
	p->pNext=e;
}

PEVENT pop_event(PEL pList){
	//return the pointer of the first event in the event list
	return pList->pFirst->pNext;
}

void delete_event(PEL pList){
	if(pList->pFirst->pNext!=NULL){
		PEVENT p=pList->pFirst->pNext;
		pList->pFirst->pNext=p->pNext;
		free(p);
	}
}

void free_eventlist(PEL pList){//release storage for all events in the list
	PEVENT p=pList->pFirst->pNext;
	while(p!=NULL){
		free(pList->pFirst);
		pList->pFirst=p;
		p=p->pNext;
	}
	free(pList->pFirst);
}
