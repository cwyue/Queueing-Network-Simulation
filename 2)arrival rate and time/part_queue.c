/*

 *  Created on: 2016Äê9ÔÂ29ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include "part_queue.h"

void init_queue(PQUEUE pQ){
	//Let the pTail of this queue point to a head node
	pQ->pTail=(PPART)malloc(sizeof(PART));
	if(pQ->pTail==NULL){
			exit(-1);
		}
	pQ->pTail->pBefore=NULL;
}

void add_parts(PQUEUE pQ,double serve,double generate){
	/*insert a part to the end of this queue and let its
	 * pNext point to its previous part
	 */
	PPART pPart=(PPART)malloc(sizeof(PART));
	if(pPart==NULL){
		exit(-1);
	}
	pPart->generate=generate;
	pPart->service_time=serve;
	pPart->pBefore=pQ->pTail->pBefore;
	pQ->pTail->pBefore=pPart;
}

void delete_parts(PQUEUE pQ){
	/*delete the first part of the queue and release
	 * the corresponding storage
	 */
	PPART p=pQ->pTail;
	if(p->pBefore!=NULL){
		while(p->pBefore->pBefore!=NULL){
			p=p->pBefore;
		}
		free(p->pBefore);
		p->pBefore=NULL;
	}
}

PPART pop_part(PQUEUE pQ){ //pass the pointer to the first part in the queue
	PPART p=pQ->pTail;
	if(p->pBefore!=NULL){
		while(p->pBefore->pBefore!=NULL){
			p=p->pBefore;
		}
	}
	return p->pBefore;
}

void free_partqueue(PQUEUE pQ){//release storage for all parts in the queue
	PPART q=pQ->pTail->pBefore;
		while(q!=NULL){
			free(pQ->pTail);
			pQ->pTail=q;
			q=q->pBefore;
		}
		free(pQ->pTail);
}



