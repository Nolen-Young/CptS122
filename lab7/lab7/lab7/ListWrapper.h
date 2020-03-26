#pragma once

#include <iostream>
#include <fstream>

#include "ListNode.h"
#include "List.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

class ListApp
{
public:
	ListApp();
	~ListApp();

	void runApp(void);

private:
	ifstream mInputStream;
	ofstream mOutputStream;
	List mList;

};

ifstream & operator>> (ifstream &input, List &rhs);