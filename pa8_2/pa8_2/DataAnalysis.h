#include "BST.h"
#include <fstream>

class DataAnalysis {
public:
	//constructor and destructor
	~DataAnalysis();

	//run
	void runAnalysis();

private:
	//functions
	void openFile();
	void readLine(int & units, std::string & data, std::string & transactionField);
	void readFile();
	void insertIntoTree(int units, std::string data, std::string transactionField);
	void trendAnalysis();

	//data members
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;
};