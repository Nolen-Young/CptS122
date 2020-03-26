#include <iostream>
#include <string>

class Node {
public:
	// constructors and destructors
	virtual ~Node();
	Node(std::string nData);

	//getters and setters
	void setData(std::string nData);
	void setRight(Node * p);
	void setLeft(Node * p);

	std::string getData();
	Node *& getRight();
	Node *& getLeft();

	//other
	virtual void printData() = 0;

protected:
	std::string mData;
	Node * mpRight;
	Node * mpLeft;
};

class TransactionNode:public Node {
public:
	//constructors and destructors
	~TransactionNode();
	TransactionNode(int nUnits, std::string nData);

	//getters and setters
	void setUnits(int nUnits);
	int getUnits();

	//other
	void printData();
private:
	int mUnits;
};