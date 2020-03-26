#include <iostream>;
#include <string>;
#include "Stack.h";

class node {
public:
	//getters and setters, don't really need setters for this assignment
	int get_record_number();
	int get_id_number();
	std::string get_name();
	std::string get_email();
	std::string get_credits();
	std::string get_major();
	std::string get_level();
	int get_absences();
	void set_absences(int new_absences);
	node * get_pNext();
	void set_pNext(node * new_pNext);

	//constructors and destructors
	node();
	node(int record_number, int id_number, int absences, stack absence_dates, std::string name, std::string email, std::string credits, std::string major, 
	std::string level, node * pNext);
	~node(); //finish this

private:
	int record_number;
	int id_number;
	int absences;
	stack absence_dates;
	std::string name;
	std::string email;
	std::string credits; // must be a string incase of AU
	std::string major;
	std::string level;
	node * pNext;
};

