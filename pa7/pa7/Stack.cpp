#include "Stack.h"

void stack::push(std::string new_string) {
	if (!isEmpty()) {
		int i = 0;

		// finds the last date
		while (this->date_list[i] != "" || i != 179);
			i++; 

		// pushes all the strings back 1
		while (i != 0) {
			this->date_list[i] = this->date_list[i - 1];
			i--;
		}

		// sets the new string;
		this->date_list[0] = new_string;
	}
	else { // if the list is empty
		this->date_list[0] = new_string;
	}
}

std::string stack::pop() {
	if (!isEmpty()) {
		std::string temp;
		int i = 0;
		temp = this->date_list[0];

		// moves all dates down in the stack
		while (this->date_list[i + 1] != "") {
			this->date_list[i] = this->date_list[i + 1];
			i++;
		}
		return temp;
	}
	else {
		return ""; // returns null string if there is nothing in the stack
	}
}

std::string stack::peek() {
	return this->date_list[0];
}

bool stack::isEmpty() {
	bool result = false;
	if (this->date_list[0] == "") {
		result = true;
	}
	return result;
}

void stack::set_date_list(std::string date_list[180]) {
	for (int i = 0; i < 180; i++) {
		this->date_list[i] = date_list[i];
	}
}



stack::stack() {
	this->date_list[180] = { "" };
}

stack::stack(std::string datelist[]) {
	for (int i = 0; i < 180; i++) {
		this->date_list[i] = datelist[i];
	}
}

stack::~stack()
{
}

stack & stack::operator=(stack & tha_stack) {
	this->set_date_list(tha_stack.date_list); // this might not work
	return *this;
}
