/*
Nolen Young
9-6-17
cpts122
pa 1
Description: This program takes in fitbit data and computes various statistics about that data.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
So this program isn't working full. The bad sleep finder function I have for some reason crashes on the last
string copy of that function and for the life of me I cannot figure out why.
If that strncpy works then the entire program should work for sure.
The problem is at the very end of my bad_sleep function.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/



#include "pa1.h"

int main(void)
{
	char line[100] = "", copyLine[100] = "", minutes[9], calories[12], distance[24], floors[5], heartRate[5], steps[6], sleep[1];
	FitbitData data[1445] = { { "", 0.0, 0.0, 0, 0, 0, NONE } };
	int i = 0;
	char temp = '\0', temp2 = '\0';

	double total_calories = 0, total_distance = 0, avg_heartrate = 0;
	int total_floors = 0, total_steps = 0, max_steps = 0;
	char *sleep_start = "", *sleep_end = "";

	FILE *outfile = NULL;
	FILE *infile = NULL;

	outfile = fopen("Results.csv", "w");
	infile = fopen("FitbitData.csv", "r");

	if (infile != NULL) {
		// opended the file successfully
		// read the line

		fgets(line, 100, infile); // get the first line - header info
		fputs(line, stdout);


		while (!feof(infile)) {
			fgets(line, 100, infile); // get the second line - fitbit data
			strcpy(copyLine, line); // preserve the original line

			int size = strlen(copyLine);

			if (copyLine[size - 2] == ',') {
				copyLine[size - 1] = '0';
				copyLine[size] = '\0';
			}

			temp = '\0';
			temp2 = '\0';

			for (int x = 0; copyLine[x + 1] != '\0'; x++) {
				if (copyLine[x] == ',' && copyLine[x + 1] == ',') {
					temp = copyLine[x + 1];
					for (int i = x + 1; i < size; i++) {
						temp2 = copyLine[i + 1];
						copyLine[i + 1] = temp;
						temp = temp2;
					}
					copyLine[x + 1] = '0';
				}
			}

			strcpy(minutes, strtok(copyLine, ",")); // grab the minutes token, separated by comma
			strcpy(data[i].minute, minutes);

			strcpy(calories, strtok(NULL, ",")); // grab the minutes token, separated by comma
			data[i].calories = atof(calories);

			strcpy(distance, strtok(NULL, ",")); // distance
			data[i].distance = atof(distance);

			strcpy(floors, strtok(NULL, ",")); // floors
			data[i].floors = atof(floors);

			strcpy(heartRate, strtok(NULL, ",")); // heartRate
			data[i].heartRate = atof(heartRate);
			
			strcpy(steps, strtok(NULL, ",")); // steps
			data[i].steps = atof(steps);

			strcpy(sleep, strtok(NULL, ",")); // sleep
			data[i].sleepLevel = atof(sleep);

			i++;
		}
	}

	total_calories = total_calories_burned(data);
	total_distance = total_distance_walked(data);
	total_floors = total_floors_walked(data);
	total_steps = total_steps_taken(data);
	avg_heartrate = avg_heart_rate(data);
	max_steps = max_steps_taken(data);
	bad_sleep(sleep_start, sleep_end, data);

	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d,%s:%s", total_calories, total_distance, total_floors, total_steps, avg_heartrate, max_steps, sleep_start, sleep_end);
	

	fclose(infile);
	return 0;
}