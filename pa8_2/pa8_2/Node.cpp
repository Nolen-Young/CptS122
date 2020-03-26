#include "Node.h"

Node::~Node()
{
}

Node::Node(std::string nData) {
	this->mData = nData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

void Node::setData(std::string nData) {
	this->mData = nData;
}

void Node::setRight(Node * p) {
	this->mpRight = p;
}

void Node::setLeft(Node * p) {
	this->mpLeft = p;
}

std::string Node::getData() {
	return this->mData;
}

Node *& Node::getRight() {
	return this->mpRight;
}

Node *& Node::getLeft() {
	return (this->mpLeft);
}


TransactionNode::~TransactionNode() {
	//std::cout << "DESTROY";
}

TransactionNode::TransactionNode(int nUnits, std::string nData) : Node (nData) , mUnits(nUnits) {
}

void TransactionNode::setUnits(int nUnits) {
	this->mUnits = nUnits;
}

int TransactionNode::getUnits() {
	return this->mUnits;
}

void TransactionNode::printData() {
	std::cout << this->mData << ": " << this->mUnits;
}






