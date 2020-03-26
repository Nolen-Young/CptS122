#include <string>
#include <iostream>
using std::string;

class Person {
public:
	//getters and setters
	string get_name();
	int get_age();
	string get_gender();
	int get_height();

	void set_name(string newName);
	void set_age(int newAge);
	void set_gender(string newGender);
	void set_height(int newHeight);

	//constructors and destructors
	Person(string name, int age, string gender, int height);
	Person(Person &obj);
	~Person();

	//other
	Person & Person::operator=(Person & person);

private:
	string name;
	int age;
	string gender;
	int heightInches;
};
std::ostream & operator<<(std::ostream &out, Person &rhs);
std::istream & operator<<(std::istream &in, Person &rhs);