#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum boolean {
	FALSE, TRUE
}Boolean;

typedef struct data
{
	int customerNumber;
	int serviceTime;
	int totalTime;
} Data;

typedef struct node {
	Data * data;
	struct Node * pNext;
}Node;

typedef struct queue {
	Node * pHead;
	Node * pTail;
}Queue;

Node * makeNode(int customerNumber, int serviceTime, int totalTime);
void makeQueue(Queue * newQueue);
Boolean isEmpty(Queue * q);
Boolean enqueue(Queue *pQueue, int customerNumber, int serviceTime, int totalTime);
void dequeue(Queue * pQueue);
void printQueue(Queue * queue);
void incrementTotalTime(Queue * q);