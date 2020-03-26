#include "pa4.h"

Node * makeNode(int customerNumber, int serviceTime, int totalTime) {
	Node * pMem = (Node*)malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->pNext = NULL;
		pMem->data = (Data*)malloc(sizeof(Data));
		if (pMem->data != NULL) {
			pMem->data->customerNumber = customerNumber;
			pMem->data->serviceTime = serviceTime;
			pMem->data->totalTime = totalTime;
		}
	}
	return pMem;
}

void makeQueue(Queue *newQueue) {
	newQueue->pHead = NULL;
	newQueue->pTail = NULL;
	return newQueue;
}

Boolean isEmpty(Queue * q) {
	Boolean status = FALSE;
	if (q->pHead == NULL) {
		status = TRUE;
	}
	return status;
}

Boolean enqueue(Queue *pQueue, int customerNumber, int serviceTime, int totalTime) {
	Queue * pMem = NULL;
	pMem = makeNode(customerNumber, serviceTime, totalTime);

	Boolean success = FALSE;

	if (pMem != NULL) { // if the node was made
		success = TRUE;

		if (isEmpty(pQueue)) {
			pQueue->pHead = pMem;
		}
		else {
			pQueue->pTail->pNext = pMem;
		}
		pQueue->pTail = pMem;
	}
	return success;
}
void dequeue(Queue * pQueue) {
	Node * pCur = pQueue->pHead;

	if (isEmpty(pQueue) == FALSE) {
		pQueue->pHead = pCur->pNext;
		free(pCur->data);
		free(pCur);
	}
}


void printQueue(Queue * queue) {
	Node * pCur = queue->pHead;
	printf("-> ");
	if (queue->pHead != NULL) {
		while (pCur->pNext != NULL) {
			printf("%d -> ", pCur->data->customerNumber);
			pCur = pCur->pNext;
		}
	}
	printf("END\n");
}

void incrementTotalTime(Queue * q) {
	Node * pCur = q->pHead;
	while (pCur != NULL) {
		pCur->data->totalTime += 1;
		pCur = pCur->pNext;
	}
}
