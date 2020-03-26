#include "Node.h"

class BST {
public:
	// destructor and constructor
	~BST();
	BST();
	//setter and getter
	Node * getRoot();
	void setRoot(Node * p);
	//other
	void insert(std::string nData, int nUnits);
	void inOrderTraversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();

private:
	void inOrderTraversal(Node * path);
	void pInsert(Node * & path, std::string nData, int nUnits);
	Node * mpRoot;
	void destroyTree(Node * pCur);
};