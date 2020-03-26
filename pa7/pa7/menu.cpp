#include "menu.h"
#include <fstream>
#include <iostream>

void menu::run() {
	int selection = 0;
	while (selection != 7) {
		print_menu();
		std::cin >> selection;

		switch (selection) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:

			break;
		}
		std::cout << std::endl;
	}
}

void menu::print_menu() {
	std::cout << "1. Import Course File" << std::endl
		<< "2. Load Master List" << std::endl
		<< "3. Store Master List" << std::endl
		<< "4. Mark Absences" << std::endl
		<< "5. Edit Absences (NOT WORKING)" << std::endl
		<< "6. Generate Report" << std::endl
		<< "7. Exit" << std::endl
		<< "> ";
}

void menu::import_course_file() {
	std::string temp;
	int record_number;
	int id_number, int absences;
	stack absence_dates;
	std::string name;
	std::string email;
	std::string credits;
	std::string major;
	std::string level;
	node * pNext = nullptr;

	std::ifstream file;
	file.open("classList.csv");
	std::getline(file, temp); // parses usesless line
	while (file.eof()) {
		std::getline(file, temp, ',');
		node * temp = new node;
		temp->set_
	}
}

menu::menu() {
}

menu::~menu() {
	delete &(this->thaList);
	
}
