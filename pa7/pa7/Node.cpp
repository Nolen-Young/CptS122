#include "Node.h"

int node::get_record_number() {
	return this->record_number;
}

int node::get_id_number() {
	return this->id_number;
}

std::string node::get_name() {
	return this->name;
}

std::string node::get_email() {
	return this->email;
}

std::string node::get_credits() {
	return this->credits;
}

std::string node::get_major() {
	return this->major;
}

std::string node::get_level() {
	return this->level;
}

int node::get_absences() {
	return this->absences;
}

void node::set_absences(int new_absences) {
	this->absences = new_absences;
}

node * node::get_pNext() {
	return this->pNext;
}

void node::set_pNext(node * new_pNext) {
	this->pNext = new_pNext;
}


node::node() {
	this->record_number = 0;
	this->id_number = 0;
	this->absence_dates;
	this->name = "";
	this->email = "";
	this->credits = "";
	this->major = "";
	this->level = "";
	this->pNext = nullptr;
}

node::node(int record_number, int id_number, int absences, stack absence_dates, std::string name, std::string email, std::string credits, std::string major, std::string level, node * pNext) {
	this->record_number = record_number;
	this->id_number = id_number;
	this->absence_dates = absence_dates;
	this->name = name;
	this->email = email;
	this->credits = credits;
	this->major = major;
	this->level = level;
	this->pNext = pNext;
}

node::~node() {
	delete &(this->absence_dates);
}
