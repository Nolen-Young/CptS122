#include "pa5.h"

void FitnessAppWrapper::runApp(void) {
	int choice = -1;
	fDietPlan.open("dietPlans.txt", ios::binary);
	fExercisePlan.open("exercisePlans.txt", ios::binary);

	while (choice != 9) {
		displayMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			loadWeeklyPlan(fDietPlan, dietWeek);
			break;
		case 2:
			loadWeeklyPlan(fExercisePlan, exerciseWeek);
			break;
		case 3:
			storeWeeklyPlan(fDietPlan, dietWeek);
			break;
		case 4:
			storeWeeklyPlan(fExercisePlan, exerciseWeek);
			break;
		case 5:
			displayWeeklyPlan(dietWeek);
			break;
		case 6:
			displayWeeklyPlan(exerciseWeek);
			break;
		case 7:

			break;
		case 8:

			break;
		case 9:
			storeWeeklyPlan(fDietPlan, dietWeek);
			storeWeeklyPlan(fExercisePlan, exerciseWeek);
			break;
		default:
			printf("Invalid selection");
			break;
		};
		cout << endl;
	}
	fDietPlan.close();
	fExercisePlan.close();
}

void FitnessAppWrapper::displayMenu(void) {
	cout << 
		"1.    Load weekly diet plan from file." << endl <<
		"2.    Load weekly exercise plan from file." << endl <<
		"3.    Store weekly diet plan to file." << endl <<
		"4.    Store weekly exercise plan to file." << endl <<
		"5.    Display weekly diet plan to screen." << endl <<
		"6.    Display weekly exercise plan to screen." << endl <<
		"7.    Edit daily diet plan." << endl <<
		"8.    Edit daily exercise plan." << endl <<
		"9.    Exit." 
		<< endl;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, ExercisePlan &plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan &plan) {
	cout << plan;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan &plan) {
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, DietPlan &plan) {
	fileStream << plan;
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, ExercisePlan&plan) {
	fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}