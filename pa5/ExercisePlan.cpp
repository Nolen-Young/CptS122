#include "pa5.h"

void ExercisePlan::setGoal(int n) {
	goal = n;
}

void ExercisePlan::setName(string n) {
	name = n;
}

void ExercisePlan::setDate(string n) {
	date = n;
}

int ExercisePlan::getGoal() {
	return goal;
}

string ExercisePlan::getName() {
	return name;
}

string ExercisePlan::getDate() {
	return date;
}

ExercisePlan::ExercisePlan() {
	goal = 0;
	name = "";
	date = "";
}

ExercisePlan::ExercisePlan(int nGoal, string nName, string nDate) {
	goal = nGoal;
	name = nName;
	date = nDate;
}

ExercisePlan::~ExercisePlan() {
}

void ExercisePlan::editGoal() {
	int nGoal;
	cout << "Enter a new calorie goal: ";
	cin >> nGoal;
	goal = nGoal;
}

void ExercisePlan::operator=(ExercisePlan rhs) {
	goal = rhs.goal;
	name = rhs.name;
	date = rhs.date;
}

std::fstream &operator<<(std::fstream &lhs, ExercisePlan &rhs) {
	lhs << rhs.getName() << endl << rhs.getGoal() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

std::fstream &operator >> (std::fstream &lhs, ExercisePlan &rhs) {
	int goal = 0;
	string name = "", date = "", temp = "";

	std::getline(lhs, name);
	rhs.setName(name);
	lhs >> goal;
	rhs.setGoal(goal);
	lhs >> date;
	rhs.setDate(date);
	lhs >> temp; //this parses through the blank line;

	return lhs;
}

std::ostream & operator<<(ostream & os, ExercisePlan & plan) {
	os << plan.getName() << endl << plan.getGoal() << endl << plan.getDate() << endl << endl;

	return os;
}
