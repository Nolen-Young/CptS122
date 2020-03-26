#include "ListNode.h"

ListNode::ListNode(int newData)
{
	mData = newData;
	mpNext = nullptr;
}

ListNode::ListNode(const ListNode &copy)
{
	mData = copy.mData;
	mpNext = copy.mpNext;
}

ListNode::~ListNode()
{
	cout << "Inside ListNode's destructor!" << endl;
}

int ListNode::getData() const
{
	return mData;
}

ListNode * ListNode::getNextPtr() const
{
	return mpNext;
}

void ListNode::setData(const int newData)
{
	mData = newData;
}

void ListNode::setNextPtr(ListNode * const pNewNext) 
{
	mpNext = pNewNext;
}