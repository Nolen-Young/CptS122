

class Node {
public:
	Node();
	~Node();

	Character * getMonster();
	void setMonster(Character * nm);

	Character * getNext();
	void setNext(Character * nNext);

private:
	Character * pNext;
	Character * monster;
};

class LinkedList{
public:
	LinkedList();
	~LinkedList();

	Node * getHead();
	void setHead(Node * nHead);

	void insertAtFront(Node * pNew);

private:
	Node * pHead;
};