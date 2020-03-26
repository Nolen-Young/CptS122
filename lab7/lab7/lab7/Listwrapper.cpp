#include "ListWrapper.h"

ListApp::ListApp()
{
	mInputStream.open("ExamScores.csv", ios::in); 
	mOutputStream.open("ExamStats.txt", ios::out); 
}

ListApp::~ListApp()
{
	cout << "Inside ListApp's destructor! Closing open files!" << endl;
	if (mInputStream.is_open()) 
	{
		mInputStream.close();
	}
	if (mOutputStream.is_open())
	{
		mOutputStream.close();
	}
}

void ListApp::runApp(void)
{
	if (mInputStream.is_open())
	{
		mInputStream >> mList;
		cout << mList;
	}

	if (mOutputStream.is_open())
	{
		mOutputStream << "High score: " << mList.computeMax() << endl;
		mOutputStream << "Mean score: " << mList.computeMean() << endl;
		mOutputStream << "Low score: " << mList.computeMin() << endl;
	}
}

ifstream & operator>> (ifstream &input, List &rhs)
{
	char line[100] = "";
	input.getline(line, 100);

	while (!input.eof())
	{
		input.getline(line, 100, ',');
		input.getline(line, 100, ',');
		input.getline(line, 100); 
		int score = atoi(line);
		rhs.insertAtFront(score);
	}

	return input;
}