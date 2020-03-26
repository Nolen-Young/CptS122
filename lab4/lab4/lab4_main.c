#include "lab4.h"

int main(void) {
	char * data1 = "Computer",
		* data2 = "Science",
		* data3 = "122";

	char test[100] = "";

	Node * pHead = NULL;
	Node * pTail = NULL;
	Queue pQueue;
	pQueue.pHead = pHead;
	pQueue.pTail = pTail;


	enqueue(&pQueue, data1);
	enqueue(&pQueue, data2);
	enqueue(&pQueue, data3);
	printQueueRecursive(pQueue.pHead);
	strcpy(test, dequeue(&pQueue));
	printQueueRecursive(pQueue.pHead);
	strcpy(test, dequeue(&pQueue));
	printQueueRecursive(pQueue.pHead);
	strcpy(test, dequeue(&pQueue));
	printQueueRecursive(pQueue.pHead);
}