#include "pa1.h"

double total_calories_burned(FitbitData data[1440]) {
	double total_calories = 0;
	for (int i = 0; i <= 1440; i++) {
		total_calories += data[i].calories;
	}
	return total_calories;
}

double total_distance_walked(FitbitData data[1440]) {
	double total_distance = 0;
	for (int i = 0; i <= 1440; i++) {
		total_distance += data[i].distance;
	}
	return total_distance;
}

int total_floors_walked(FitbitData data[1440]) {
	int total_floors = 0;
	for (int i = 0; i <= 1440; i++) {
		total_floors += data[i].floors;
	}
	return total_floors;
}

int total_steps_taken(FitbitData data[1440]) {
	int total_steps = 0;
	for (int i = 0; i <= 1440; i++) {
		total_steps += data[i].steps;
	}
	return total_steps;
}

double avg_heart_rate(FitbitData data[1440]) {
	int total_beats = 0;
	double avg_heart_rate;
	for (int i = 0; i <= 1440; i++) {
		total_beats += data[i].heartRate;
	}
	avg_heart_rate = total_beats / 1440;
	return avg_heart_rate;
}

int max_steps_taken(FitbitData data[1440]) {
	int max = 0;
	for (int i = 0; i <= 1440; i++) {
		if (data[i].steps > max) {
			max = data[i].steps;
		}
	}
	return max;
}

void bad_sleep(char * sleep_start, char * sleep_end, FitbitData data[1440]) {
	int worst_level = 0;
	int level = 0;
	char start_time[20] = "";
	char end_time[20] = "";

	for (int i = 0; i <= 1440; i++) {
		if (data[i].sleepLevel > 1){
			strncpy(start_time, data[i].minute, 9);
			while (data[i].sleepLevel > 1) {
				level += data[i].sleepLevel;
				i++;
			}
			strncpy(end_time, data[i].minute, 9);
			if (level > worst_level) {
				worst_level = level;
			}
		}
	}



	// this is where the problem is
	//strncpy(sleep_start, start_time, 9);
	//strncpy(sleep_end, end_time, 9);
}
