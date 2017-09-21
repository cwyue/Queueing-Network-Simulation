
/*
 * queue_with_N_events.c
 *
 *  Created on: 2016年9月24日
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

typedef struct event{
	double time;
	struct event * pNext;
}EVENT,* PEVENT;

typedef struct eventList{
	PEVENT pFirst;
}EL, *PEL;

void init_eList(PEL pList);
void add_event(PEL pList,double time);
PEVENT pop_event(PEL pList);
void delete_event(PEL pList);


void simulation(PEL pList,int N);
double urand(void);


void free_all(PEL pList);


void init_eList(PEL pList){
	pList->pFirst=(PEVENT)malloc(sizeof(EVENT));
	if(pList->pFirst==NULL){
		exit(-1);
	}
	pList->pFirst->pNext=NULL;
}

void add_event(PEL pList,double time){
	PEVENT e=(PEVENT)malloc(sizeof(EVENT));
	if(e==NULL){
		exit(-1);
	}
	e->time=time;
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
	return pList->pFirst->pNext;
}

void delete_event(PEL pList){
	if(pList->pFirst->pNext!=NULL){
		PEVENT p=pList->pFirst->pNext;
		pList->pFirst->pNext=p->pNext;
		free(p);
	}
}

void simulation(PEL pList,int N){
	init_eList(pList);
	srand(time(0));
	int count=0;
	/*create N events whose timestamps are uniformly distributed
	 *between (0,1] and push them into the priority queue.
	  */
	for(int i=0;i<N;i++){
		add_event(pList,urand());
	}
	struct timeval start, finish;
	/*these two variables can store system time. They have two attributes:
	 tv_sec and tv_usec, which can store second and microsecond respectively
	 */

	gettimeofday(&start, NULL);//this function can obtain system time
	while(count<=5000){         // do 5000 iterations
		add_event(pList,urand());
		delete_event(pList);
		count++;
	}
	gettimeofday(&finish, NULL);//record system time again after 5000 loops
	double duration=(finish.tv_sec-start.tv_sec)*1000000+(finish.tv_usec-start.tv_usec);
	printf("%d\t %f\t %f\n",N,duration,duration/count);
	free_all(pList);

}
double urand(void){
	return rand()/(RAND_MAX+1.0);
}

void free_all(PEL pList){
	PEVENT p=pList->pFirst->pNext;
	while(p!=NULL){
		free(pList->pFirst);
		pList->pFirst=p;
		p=p->pNext;
	}
	free(pList->pFirst);
	pList->pFirst=NULL;
}

void show_list(PEL pList){
	PEVENT p=pList->pFirst->pNext;
	while(p!=NULL){
		printf("%.2f\n",p->time);
		p=p->pNext;
	}
	printf("\n");
}


int main(void){
	EL event_list;
	printf("N:\t total time:\t average time:\n");
	/* change the value of N and collect the corresponding average time
	 */
	for(int N=1000;N<=40000;N+=2000){
		simulation(&event_list,N);
	}

	return 0;
}




