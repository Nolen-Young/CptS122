#include "Person.h"

string Person::get_name() {
	return this->name;
}

int Person::get_age(){
	return this->age;
}

string Person::get_gender() {
	return this->gender;
}

int Person::get_height() {
	return this->heightInches;
}

void Person::set_name(string newName) {
	this->name = newName;
}

void Person::set_age(int newAge) {
	this->age = newAge;
}

void Person::set_gender(string newGender) {
	this->gender = newGender;
}

void Person::set_height(int newHeight) {
	this->heightInches = newHeight;
}

Person::Person(string name, int age, string gender, int height) {
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->heightInches = height;
}

Person::Person(Person & obj) {
	this->name = obj.get_name();
	this->age = obj.get_age();
	this->gender = obj.get_gender();
	this->heightInches = obj.get_height();
}

Person::~Person() {
}

Person & Person::operator=(Person & person) {
	this->name = person.get_name();
	this->age = person.get_age();
	this->gender = person.get_gender();
	this->heightInches = person.get_height();
	return *this;
}

std::ostream & operator<<(std::ostream & out, Person & rhs) {
	out << rhs.get_name() << std::endl;
	out << rhs.get_age() << std::endl;
	out << rhs.get_gender() << std::endl;
	out << rhs.get_height() << std::endl;

	return out;
}

std::istream & operator<<(std::istream & in, Person & rhs) {
	int iTemp;
	string sTemp;

	in >> sTemp;
	rhs.set_name(sTemp);
	in >> iTemp;
	rhs.set_age(iTemp);
	in >> sTemp;
	rhs.set_gender(sTemp);
	in >> iTemp;
	rhs.set_height(iTemp);

	return in;
}
