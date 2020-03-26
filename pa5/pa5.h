#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::string;

class DietPlan {
private:
	int goal;
	string name;
	string date;
public:
	//setters
	void setGoal(int n);
	void setName(string n);
	void setDate(string n);
	//getters
	int getGoal();
	string getName();
	string getDate();
	//constructor and destructor
	DietPlan();
	DietPlan(int nGoal, string nName, string nDate);
	~DietPlan();
	//misc
	void editGoal();
	void operator=(DietPlan rhs);
};
//operator overloads
std::fstream &operator<<(std::fstream &lhs, DietPlan &rhs);
std::fstream &operator>>(std::fstream &lhs, DietPlan &rhs);
std::ostream& operator<<(ostream& os, DietPlan& plan);

class ExercisePlan {
private:
	int goal;
	string name;
	string date;
public:
	//setters
	void setGoal(int n);
	void setName(string n);
	void setDate(string n);
	//getters
	int getGoal();
	string getName();
	string getDate();
	//constructor and destructor
	ExercisePlan();
	ExercisePlan(int nGoal, string nName, string nDate);
	~ExercisePlan();
	//misc
	void editGoal();
	void operator=(ExercisePlan rhs);
};
//operator overloads
std::fstream &operator<<(std::fstream &lhs, ExercisePlan &rhs);
std::fstream &operator >> (std::fstream &lhs, ExercisePlan &rhs);
std::ostream& operator<<(ostream& os, ExercisePlan& plan);

class FitnessAppWrapper {
private:
	DietPlan dietWeek[7];
	ExercisePlan exerciseWeek[7];
	std::fstream fDietPlan;
	std::fstream fExercisePlan;
public:
	void runApp(void);
	void displayMenu(void);
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
	void displayDailyPlan(DietPlan &plan);
	void displayDailyPlan(ExercisePlan &plan);
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
	void storeDailyPlan(fstream &fileStream, DietPlan &plan);
	void storeDailyPlan(fstream &fileStream, ExercisePlan&plan);
	void storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
};