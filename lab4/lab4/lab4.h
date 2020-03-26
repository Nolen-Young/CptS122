#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean {
	FALSE, TRUE
}Boolean;

typedef struct node {
	char * data;
	struct Node * pNext;
}Node;

typedef struct queue{
	Node * pHead;
	Node * pTail;
}Queue;

Node * makeNode(char * newData);
Boolean isEmpty(Queue q);
Boolean enqueue(Queue *pQueue, char * newData); 
char * dequeue(Queue * pQueue);
void printQueueRecursive(Node * pHead);
