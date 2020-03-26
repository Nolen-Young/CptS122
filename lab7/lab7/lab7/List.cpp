#include "List.h"

List::List()                    
{
	mpHead = nullptr;
}

List::List(const List &copyList)     
{
	mpHead = new ListNode;

	ListNode *cur1 = mpHead;
	ListNode *cur2 = copyList.getHeadPtr(); 
	
	cur1->setData(cur2->getData());
	cur2 = cur2->getNextPtr();

	while (cur2 != nullptr)
	{
		int data = cur2->getData();
		cur1->setNextPtr(new ListNode(data)); 

		cur1 = cur1->getNextPtr();
		cur2 = cur2->getNextPtr();
	}
}

List::~List()
{
	cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}


List & List::operator= (const List &rhs)
{
	mpHead = new ListNode;

	ListNode *cur1 = mpHead;
	ListNode *cur2 = rhs.getHeadPtr();

	cur1->setData(cur2->getData());
	cur2 = cur2->getNextPtr();

	while (cur2 != nullptr)
	{
		int data = cur2->getData();
		cur1->setNextPtr(new ListNode(data));
		cur1 = cur1->getNextPtr();
		cur2 = cur2->getNextPtr();
	}

	return (*this);
}

ListNode * List::getHeadPtr() const
{
	return mpHead;
}

void List::setHeadPtr(ListNode * const pNewHead) 
{
	mpHead = pNewHead;
}

bool List::insertAtFront(const int newData)
{
	ListNode *pMem = makeNode(newData);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

bool List::insertInOrder(const int newData)     
{
	bool success = false;

	ListNode *insertMe = new ListNode(newData);
	ListNode *pPrev = nullptr;
	ListNode *pCur = mpHead;

	if (pCur == nullptr)
	{
		mpHead = insertMe;
		success = true;
	}
	else
	{
		while (pCur != nullptr && newData > pCur->getData())
		{
			pPrev = pCur;
			pCur = pCur->getNextPtr();
		}

		if (pCur == nullptr)
		{
			pPrev->setNextPtr(insertMe);
			success = true;
		}
		else if (pPrev != nullptr)
		{
			insertMe->setNextPtr(pCur);
			pPrev->setNextPtr(insertMe);
			success = true;
		}
		else
		{
			insertMe->setNextPtr(mpHead);
			mpHead = insertMe;
			success = true;
		}

	}
	return success;
}

bool List::insertAtEnd(const int newData)       
{
	bool success = false;

	ListNode *insertMe = new ListNode(newData);
	ListNode *pCur = mpHead;

	if (pCur == nullptr)
	{
		mpHead = insertMe;
	}
	else
	{
		while (pCur->getNextPtr() != nullptr)
		{
			pCur = pCur->getNextPtr();
		}
		pCur->setNextPtr(insertMe);
	}

	return success;
}

bool List::isEmpty()                           
{
	return (mpHead == nullptr);
}

int List::deleteAtFront()                       
{
	int data = 0;

	ListNode *deleteMe = mpHead;
	if (mpHead != nullptr)
	{
		data = mpHead->getData();
		mpHead = mpHead->getNextPtr();
		delete deleteMe;
	}

	return data;
}

bool List::deleteNode(const int searchValue)    
{
	bool success = false;

	ListNode *pPrev = nullptr;
	ListNode *pCur = mpHead;
	if (mpHead != nullptr) 
	{
		while (pCur != nullptr && pCur->getData() != searchValue) 
		{
			pPrev = pCur;
			pCur = pCur->getNextPtr();
		}
		if (pCur != nullptr)
		{
			if (pPrev != nullptr) 
			{
				pPrev->setNextPtr(pCur->getNextPtr());
				delete pCur;
				success = true;
			}
			else
			{
				mpHead = mpHead->getNextPtr();
				delete pCur;
				success = true;
			}
		}
	}

	return success;
}

int List::deleteAtEnd()                         
{
	int data = 0;

	if (mpHead != nullptr)
	{
		ListNode *pCur = mpHead;
		ListNode *pPrev = mpHead;
		while (pCur->getNextPtr() != nullptr)
		{
			pPrev = pCur;
			pCur = pCur->getNextPtr();
		}
		if (pCur != mpHead)
		{
			data = pCur->getData();
			delete pCur;
			pPrev->setNextPtr(nullptr);
		}
		else
		{
			data = pCur->getData();
			delete pCur;
			mpHead = nullptr;
		}
	}
	

	return data;
}

void List::printList()                          
{
	ListNode *pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}
}

int List::computeMax()
{
	int highScore = 0;

	ListNode *pCur = mpHead;
	while (pCur != nullptr)
	{
		if (pCur->getData() > highScore)
			highScore = pCur->getData();
		pCur = pCur->getNextPtr();
	}

	return highScore;
}

int List::computeMin()
{
	int lowScore = mpHead->getData();

	ListNode *pCur = mpHead->getNextPtr();
	while (pCur != nullptr)
	{
		if (pCur->getData() < lowScore)
			lowScore = pCur->getData();
		pCur = pCur->getNextPtr();
	}

	return lowScore;
}

int List::computeMean()
{
	int cumalitiveScore = 0;
	int numberOfNodes = 0;

	ListNode *pCur = mpHead;
	while (pCur != nullptr)
	{
			cumalitiveScore += pCur->getData();
			numberOfNodes++;
			pCur = pCur->getNextPtr();
	}

	return cumalitiveScore / numberOfNodes;
}


ListNode * List::makeNode(const int newData)
{
	ListNode *pMem = new ListNode(newData);

	return pMem;
}

void List::destroyListHelper(ListNode * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;
	}
}

void List::destroyList()                        
{
	destroyListHelper(mpHead);
}

ostream & operator<< (ostream &output, const List &rhs)
{
	ListNode *pCur = rhs.getHeadPtr();

	while (pCur != nullptr)
	{
		output << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}

	return output;
}