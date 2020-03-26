#include <iostream>
#include <string>
#include <fstream>
#include "List.h";

class menu {
public:
	void run();
	void print_menu();
	void import_course_file();
	void load_master_list();
	void store_master_list();
	void mark_absences();
	void generate_report();

	menu();
	~menu();

private:
	list thaList;
};