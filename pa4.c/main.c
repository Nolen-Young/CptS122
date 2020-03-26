/*
Nolen Young
last edited: 10-3-17
PA4, lab section 14
This program simulates a grocery checkout lane and an express grocery checkout lane.
*/



#include "pa4.h"

int main(void) {
	//initiating variables we will need
	Queue *regular = (Queue*)malloc(sizeof(Queue)),
		*express = (Queue*)malloc(sizeof(Queue));
	makeQueue(regular);
	makeQueue(express);
	int arrivalExpress = 0,
		arrivalRegular = 0,
		arrivalExpressCounter = 0, // these start at -1 so that the first customer is counted correctly
		arrivalRegularCounter = 0,
		totalMinutes = 0,
		customerCounter = 0,
		serviceTimeTemp = 0,
		expressServiceCounter = 0,// these start at -1 so that the first customer is counted correctly
		regularServiceCounter = 0;
	srand(time(NULL));
	printf("Enter how many minutes you would like to simulate: "); // get the total minutes to simulate
	scanf("%d", &totalMinutes);

	arrivalRegular = rand() % 6 + 3; // set first customer arrival time
	arrivalExpress = rand() % 5 + 1;

	for (int i = 0; i < totalMinutes + 1; i++) {
		arrivalExpressCounter++;
		arrivalRegularCounter++;
		
		

		// check if the customer at the front of the queues is done, adjust and display data accordingly
		
		if (!isEmpty(regular)) {
			if (regularServiceCounter == regular->pHead->data->serviceTime) {
				regularServiceCounter = 0;
				printf("Customer #%d left after spending %d minutes in the regular line.\n", customerCounter, regular->pHead->data->totalTime);
				dequeue(regular);
			}
			regularServiceCounter++;
		}
		if (!isEmpty(express)) {
			if (expressServiceCounter == express->pHead->data->serviceTime) {
				expressServiceCounter = 0;
				printf("Customer #%d left after spending %d minutes in the express line.\n", customerCounter, express->pHead->data->totalTime);
				dequeue(express);
			}
			expressServiceCounter++;
		}

		// check for customer arrival and create a new customer as needed
		if (arrivalRegular == arrivalRegularCounter) {
			customerCounter++;
			
			arrivalRegular = rand() % 6 + 3;
			serviceTimeTemp = rand() % 6 + 3;
			arrivalRegularCounter = 0;
			printf("Customer #%d arrived at minute %d and entered the regular line.\n", customerCounter, i);
			enqueue(regular, customerCounter, serviceTimeTemp, 0);
		}
		if (arrivalExpress == arrivalExpressCounter) {
			customerCounter++;
			arrivalExpress = rand() % 5 + 1;
			serviceTimeTemp = rand() % 5 + 1;
			arrivalExpressCounter = 0;
			printf("Customer #%d arrived at minute %d and entered the express line.\n", customerCounter, i);
			enqueue(express, customerCounter, serviceTimeTemp, 0);
		}


		//Ten minute list print
		if (i % 10 == 0 && i != 0) {
			printf("Regular Line ");
			printQueue(regular);
			printf("Express Line ");
			printQueue(express);
			printf("\n");
		}

		if (i % 1440 == 0) {
			customerCounter = 0;
		}

		//increment total times
		incrementTotalTime(regular);
		incrementTotalTime(express);
	}

	free(regular);
	free(express);
	return 1;
}