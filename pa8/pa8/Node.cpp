#include "node.h"

Node::Node(std::string newData) {
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node()
{
}

void Node::setData(std::string newData) {
	this->mData = newData;
}

void Node::setLeft(Node * nLeft) {
	this->mpLeft = nLeft;
}

void Node::setRight(Node * nRight) {
	this->mpRight = nRight;
}

std::string Node::getData() {
	return (this->mData);
}

Node * Node::getLeft() {
	return (this->mpLeft);
}

Node * Node::getRight() {
	return (this->mpRight);
}

void Node::printData() {
	std::cout << this->mData;
}

TransactionNode::TransactionNode(std::string nData, int nUnits) {
	Node::Node(nData);
	this->mUnits = nUnits;
}

TransactionNode::~TransactionNode() {
	std::cout << "DESTROY" << std::endl;
}

int TransactionNode::getUnits() {
	return this->mUnits;
}

void TransactionNode::setUnits(int nUnits) {
	this->mUnits = nUnits;
}

void TransactionNode::printData() {
	std::cout << this->getData() << ": " << this->mUnits << std::endl;
}
