#include <iostream>
#include "Node.h"

class list {
public:
	//getters and setters
	node * get_pHead();
	void set_pHead(node * new_pHead);

	//other
	void insert_at_front(node * new_node);
	bool isEmpty();

	// constructor and destructor
	list();
	list(node * pHead);
	~list();

private:
	node * pHead;
};
