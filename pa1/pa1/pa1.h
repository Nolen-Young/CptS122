#ifndef PA1_H
#define PA1_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData; 

double total_calories_burned(FitbitData data [1440]);
double total_distance_walked(FitbitData data[1440]);
int total_floors_walked(FitbitData data[1440]);
int total_steps_taken(FitbitData data[1440]);
double avg_heart_rate(FitbitData data[1440]);
int max_steps_taken(FitbitData data[1440]);
void bad_sleep(char * sleep_start, char * sleep_end, FitbitData data[1440]);

#endif