#include "lab4.h"

Node * makeNode(char * newData) {
	Node * pMem = (Node*)malloc(sizeof (Node));
	if (pMem != NULL) {
		pMem->pNext = NULL;
		pMem->data = (char*)malloc(sizeof(char) * strlen(newData) + 1);
		if (pMem->data != NULL) {
			strcpy(pMem->data, newData);
		}
	}
	return pMem;
}

Boolean isEmpty(Queue q) {
	Boolean status = FALSE;
	if (q.pHead == NULL)
	{
			status = TRUE;
	}
	return status;
}

Boolean enqueue(Queue *pQueue, char * newData) {
	Queue * pMem = NULL;
	pMem = makeNode(newData);

	Boolean success = FALSE;
	
	if (pMem != NULL) { // if the node was made
		success = TRUE;

		if (isEmpty(*pQueue)) {
			pQueue->pHead = pMem;
		} else {
			pQueue->pTail->pNext = pMem;
		}
		pQueue->pTail = pMem;
	}
	return success;
}

char * dequeue(Queue * pQueue){
	Node * pCur = pQueue->pHead;
	char data [100] = "";
	
	if (isEmpty(*pQueue) == FALSE) {
		strcpy(data, pCur->data);
		pQueue->pHead = pCur->pNext;
		free(pCur);
	}
	return data;
}

void printQueueRecursive(Node * pHead) {
	Node * pCur = pHead;

	if (pCur != NULL) {
		if (pCur->pNext != NULL) {
			printf("%s -> ", pCur->data);
			pCur = pCur->pNext;
			printQueueRecursive(pCur);
		}
		else {
			printf("%s -> NULL\n", pCur->data);
		}
	}
	else {
		printf("-> NULL\n");
	}
}
