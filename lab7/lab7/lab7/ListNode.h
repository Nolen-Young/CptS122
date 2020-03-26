#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class ListNode
{
public:
	ListNode(int newData = 0); 
	ListNode(const ListNode &copy);  
	~ListNode();               
	                   
	// getters
	int getData() const; 
	ListNode * getNextPtr() const; 

	// setters
	void setData(const int newData);
	void setNextPtr(ListNode * const pNewNext);

private:
	int mData;
	ListNode *mpNext;

	
};