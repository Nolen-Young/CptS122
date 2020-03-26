#include <iostream>
#include <string>
 
class Node {
public:
	//constructors and destructors
	Node(std::string newData);
	virtual ~Node();
	
	// setters and getters
	void setData(std::string newData);
	void setLeft(Node * nLeft);
	void setRight(Node * nRight);
	std::string getData();
	Node * getLeft();
	Node * getRight();

	virtual void printData();
private:
	std::string mData;
	Node * mpLeft;
	Node * mpRight;
};

class TransactionNode :public Node {
public:
	// constructors and destructors
	TransactionNode(std::string nData, int nUnits);
	~TransactionNode();

	// setters and getters
	int getUnits();
	void setUnits(int nUnits);

	// other
	void printData();
private:
	int mUnits;
};