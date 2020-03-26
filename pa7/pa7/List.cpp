#include "List.h"

node * list::get_pHead() {
	return this->pHead;
}

void list::set_pHead(node * new_pHead) {
	this->pHead = new_pHead;
}

void list::insert_at_front(node * new_node) {
	if (!isEmpty()) {
		new_node->set_pNext(this->pHead);
		this->pHead = new_node;
	}
	else {
		this->pHead = new_node;
	}
}

bool list::isEmpty() {
	bool result = false;
	if (this->pHead == nullptr) {
		result = true;
	}
	return result;
}

list::list() {
	this->pHead = nullptr;
}

list::list(node * pHead) {
	this->pHead = pHead;
}

list::~list() {
	node * temp;
	while (pHead != nullptr) {
		temp = this->pHead;
		this->pHead = this->pHead->get_pNext();
		delete temp;
	}
}
