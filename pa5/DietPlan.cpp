#include "pa5.h"

void DietPlan::setGoal(int n) {
	goal = n;
}

void DietPlan::setName(string n) {
	name = n;
}

void DietPlan::setDate(string n) {
	date = n;
}

int DietPlan::getGoal() {
	return goal;
}

string DietPlan::getName() {
	return name;
}

string DietPlan::getDate() {
	return date;
}

DietPlan::DietPlan() {
	goal = 0;
	name = "";
	date = "";
}

DietPlan::DietPlan(int nGoal, string nName, string nDate) {
	goal = nGoal;
	name = nName;
	date = nDate;
}

DietPlan::~DietPlan() {
	//cout << "Object is deleted" << endl;
}

void DietPlan::editGoal() {
	int nGoal;
	cout << "Enter a new calorie goal: ";
	cin >> nGoal;
	goal = nGoal;
}

void DietPlan::operator=(DietPlan rhs) {
	goal = rhs.goal;
	name = rhs.name;
	date = rhs.date;
}

std::fstream & operator<<(std::fstream & lhs, DietPlan & rhs) {
	lhs << rhs.getName() << endl << rhs.getGoal() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

std::fstream & operator >> (std::fstream & lhs, DietPlan & rhs) {
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

std::ostream & operator<<(ostream & os, DietPlan & plan) {
	os << plan.getName() << endl << plan.getGoal() << endl << plan.getDate() << endl << endl;
	return os;
}
