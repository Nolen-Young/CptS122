#include "LinkedList.h"

Node::Node() {
	this->pNext = nullptr;
	this->monster = nullptr;
}

Node::~Node() {
	delete(this->monster);
}

Character * Node::getMonster() {
	return this->monster;
}

void Node::setMonster(Character * nm) {
	this->monster = nm;
}

Character * Node::getNext() {
	return this->pNext;
}

void Node::setNext(Character * nNext) {
	this->pNext = nNext;
}

LinkedList::LinkedList() {
	this->pHead = nullptr;
}

LinkedList::~LinkedList() {
	Node * pCur = this->pHead;
	Node * pNext = this->pHead->getNext();
	while (pCur != nullptr) {
		delete(pCur);
		pCur = pNext;
		pNext = pNext->getNext();
	}
}

Node * LinkedList::getHead() {
	return this->pHead;
}

void LinkedList::setHead(Node * nHead) {
	this->pHead = nHead;
}

void LinkedList::insertAtFront(Node * pNew) {
	pNew->setNext(pHead);
	this->pHead = pNew;
}
