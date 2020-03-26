#include "lab12.h"

template<class NODETYPE>
inline ListNode<NODETYPE>::ListNode(const NODETYPE & newData) {
	this->data = newData;
}

template<class NODETYPE>
inline NODETYPE ListNode<NODETYPE>::getData() const {
	return (this->data);
}

template<class NODETYPE>
inline List<NODETYPE>::List() {
	this->firstPtr = nullptr;
	this->lastPtr = nullpter;
}

template<class NODETYPE>
inline List<NODETYPE>::~List() {

}

template<class NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE & newData) {
	ListNode<NODETYPE> * ptr = getNewNode(newData);
	ptr->nextPtr = (this->firstPtr);
	(this->firstPtr) = ptr;
}

template<class NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE & newData) {
	ListNode<NODETYPE> * ptr = getNewNode(newData);
	this->lastPtr->nextPtr = ptr;
	this->lastPtr = ptr;
}

template<class NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE & removedData) {
	removedData = this->firstPtr->data;
	ListNode<NODETYPE> * ptr = this->firstPtr;
	this->firstPtr = this->firstPtr->nextPtr;
	delete ptr;
}

template<class NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE & removedData) {
	removedData = this->lastPtr->data;
	ListNode<NODETYPE> * ptr = this->lastPtr;
	ListNode<NODETYPE> * pCur = this->firstPtr;
	while (ptr != pCur->nextPtr) {
		pCur = pCur->nextPtr;
	}
	pCur->nextPtr = nullptr;
	this->lastPtr = pCur;
	delete ptr;
}

template<class NODETYPE>
bool List<NODETYPE>::isEmpty() const {
	bool empty = false;
	if (this->firstPtr == nullptr) {
		empty = true;
	}
	return empty;
}

template<class NODETYPE>
void List<NODETYPE>::print() const {
	ListNode<NODETYPE> * pCur = this->firstPtr;
	while (pCur != nullptr) {
		std::cout << pCur->data << std::endl;
		pCur = pCur->nextPtr;
	}
}

template<class NODETYPE>
inline ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE & newData) {
	ListNode<NODETYPE> * ptr = new node(newData);
	return ptr;
}