#include <iostream>
#include <string>

template< class NODETYPE > class List;  // forward declaration

template<class NODETYPE>
class ListNode {
	friend class List< NODETYPE >; // make List a friend
public:
	ListNode(const NODETYPE &newData);  // copy constructor
	NODETYPE getData() const;      // return data in the node
private:
	NODETYPE data;                 // data
	ListNode< NODETYPE > *nextPtr; // next node in the list
};


template< class NODETYPE >
class List {
public:
	List();      // constructor
	~List();     // destructor
	void insertAtFront(const NODETYPE &newData);
	void insertAtBack(const NODETYPE &newData);
	bool removeFromFront(NODETYPE &removedData);
	bool removeFromBack(NODETYPE &removedData);
	bool isEmpty() const;
	void print() const;
private:
	ListNode< NODETYPE > *firstPtr;  // pointer to first node
	ListNode< NODETYPE > *lastPtr;   // pointer to last node

									 // Utility function to allocate a new node
	ListNode< NODETYPE > *getNewNode(const NODETYPE &newData);
};

template <class NODETYPE>
class Queue :private List {
private:

public:
	void enqueue(const NODETYPE & newData);
	bool dequeue(NODETYPE & removedData);
};

template<class NODETYPE>
inline void Queue<NODETYPE>::enqueue(const NODETYPE & newData) {
	insertAtFront(newData);
}

template<class NODETYPE>
inline bool Queue<NODETYPE>::dequeue(NODETYPE & removedData) {
	removeFromBack(removedData);
}
