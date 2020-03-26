#include <iostream>
#include <string>

class stack {
public:
	void push(std::string new_string);
	std::string pop();
	std::string peek();
	bool isEmpty();
	void set_date_list(std::string date_list[180]);

	//constructors and destructors
	stack();
	stack(std::string datelist[]);
	~stack();

	// other
	stack & stack::operator=(stack & tha_stack);

private:
	std::string date_list[180]; //chose 180 cause that's the number of days of school
};
