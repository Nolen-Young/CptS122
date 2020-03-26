#include "ListWrapper.h"

void testInsertInOrder();
void testInsertAtEnd();
void testDeleteAtFront(List &builtList);
void testDeleteNode(List &builtList);
void testDeleteAtEnd();

int main(void)
{
	testInsertInOrder();
	testInsertAtEnd();
	testDeleteAtEnd();

	ListApp app;
	cout << "Running app..." << endl;
	app.runApp();
	cout << "Check ExamStats.txt for output" << endl;
	system("pause");

	return 0;
}

void testInsertInOrder()
{
	List testList;
	
	cout <<"Testing insert in order:" << endl;
	cout << "Inserting 5" << endl;
	testList.insertInOrder(5);
	cout << "Inserting 10" << endl;
	testList.insertInOrder(10);
	cout << "Inserting -5" << endl;
	testList.insertInOrder(-5);
	cout << "Inserting 3" << endl;
	testList.insertInOrder(3);
	cout << "Inserting 20" << endl;
	testList.insertInOrder(20);
	cout << "Inserting 100" << endl;
	testList.insertInOrder(100);
	cout << "Inserting 75" << endl << endl;
	testList.insertInOrder(75);

	cout << "Final list: " << endl << testList;
	system("pause");
	testDeleteAtFront(testList);
	system("pause");
}

void testDeleteNode(List &builtList)
{
	int value = 0;
	cout << "Enter a value to delete: ";
	cin >> value;

	builtList.deleteNode(value);

	cout << "Entire List: " << endl << builtList << endl;
}

void testDeleteAtFront(List &builtList)
{
	cout << "Testing deleteAtFront(): " << endl << endl;
	while (!builtList.isEmpty())
	{
		cout << "Entire list: " << endl << builtList << endl;
		cout << "Deleting at front..." << endl;
		builtList.deleteAtFront();
	}
}

void testInsertAtEnd()
{
	List testList;

	cout << endl << "Testing insert at end" << endl;
	cout << "Inserting 5" << endl;
	testList.insertAtEnd(5);
	cout << "Inserting 10" << endl;
	testList.insertAtEnd(10);
	cout << "Inserting -5" << endl;
	testList.insertAtEnd(-5);
	cout << "Inserting 3" << endl;
	testList.insertAtEnd(3);
	cout << "Inserting 20" << endl;
	testList.insertAtEnd(20);
	cout << "Inserting 100" << endl;
	testList.insertAtEnd(100);
	cout << "Inserting 75" << endl << endl;
	testList.insertAtEnd(75);

	cout << "Final list: " << endl << testList;
	system("pause");

	testDeleteNode(testList);
	system("pause");
}

void testDeleteAtEnd()
{
	List builtList;
	builtList.insertAtEnd(12);
	builtList.insertAtEnd(33);
	builtList.insertAtEnd(55);
	cout << "Testing deleteAtEnd(): " << endl;
	cout << "New List: " << endl << builtList << endl;
	cout << "Deleting last node..." << endl;
	builtList.deleteAtEnd();
	cout << "Entire List: " << endl << builtList << endl;
	system("pause");
}