#include "BST.h"

BST::~BST() {
	destroyTree(this->mpRoot);
}

BST::BST() {
	this->mpRoot = nullptr;
}

Node * BST::getRoot() {
	return this->mpRoot;
}

void BST::setRoot(Node * p) {
	this->mpRoot = p;
}

void BST::insert(std::string nData, int nUnits) {
	this->pInsert(this->mpRoot, nData, nUnits);
}

void BST::inOrderTraversal() {
	inOrderTraversal(this->mpRoot);
}

TransactionNode & BST::findSmallest() {
	Node * pCur = this->mpRoot;
	while (pCur->getLeft() != nullptr) {
		pCur = pCur->getLeft();
	}
	return (dynamic_cast<TransactionNode &>(*pCur));
}

TransactionNode & BST::findLargest() {
	Node * pCur = this->mpRoot;
	while (pCur->getRight() != nullptr) {
		pCur = pCur->getRight();
	}
	return (dynamic_cast<TransactionNode &>(*pCur));
}

void BST::inOrderTraversal(Node * path) {
	if (path == nullptr) return;
	inOrderTraversal(path->getLeft());
	path->printData();
	std::cout << std::endl;
	inOrderTraversal(path->getRight());
}

void BST::pInsert(Node *& path, std::string nData, int nUnits) {
	if (path == nullptr) {
		TransactionNode * pMem = nullptr;
		pMem = new TransactionNode(nUnits, nData);
		path = (dynamic_cast<Node *>(pMem));
	}
	else if (nUnits > (dynamic_cast<TransactionNode *> (path)->getUnits())) {
		this->pInsert(path->getRight(), nData, nUnits);
	}
	else if (nUnits < (dynamic_cast<TransactionNode *>(path)->getUnits())) {
		this->pInsert(path->getLeft(), nData, nUnits);
	}
}

void BST::destroyTree(Node * pCur) {
	if (pCur->getLeft() != nullptr)
		destroyTree(pCur->getLeft());
	if (pCur->getRight() != nullptr)
		destroyTree(pCur->getRight());
	delete pCur;
}