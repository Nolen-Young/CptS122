#pragma once

#include <iostream>

#include "ListNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class List
{
public:
	List();
	List(const List &copyList);
	~List();

	List & operator= (const List &rhs);

	// getter
	ListNode * getHeadPtr() const;

	// setter
	void setHeadPtr(ListNode * const pNewHead); // modifies mpHead

	bool insertAtFront(const int newData); 
	bool insertInOrder(const int newData); 
	bool insertAtEnd(const int newData); 
	bool isEmpty(); 
	int deleteAtFront();  
	bool deleteNode(const int searchValue); 
	int deleteAtEnd(); 
	void printList();
	int computeMax();
	int computeMin();
	int computeMean();

private:
	ListNode *mpHead;

	ListNode * makeNode(const int newData);
	void destroyList();
	void destroyListHelper(ListNode * const pMem);
};

ostream & operator<< (ostream &output, const List &rhs);