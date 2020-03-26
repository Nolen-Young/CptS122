#include "DataAnalysis.h"

DataAnalysis::~DataAnalysis() {
	(this->mCsvStream).close();
	delete &(this->mTreePurchased);
	delete &(this->mTreeSold);
}

void DataAnalysis::runAnalysis() {
	this->openFile();
	this->readFile();
	this->trendAnalysis();
}

void DataAnalysis::openFile() {
	std::string temp;
	this->mCsvStream.open("data.csv");
	std::getline(this->mCsvStream, temp);
}

void DataAnalysis::readLine(int & units, std::string & data, std::string & transactionField) {
	std::string unitTemp = "";
	getline(this->mCsvStream, unitTemp, ',');
	units = std::stoi(unitTemp);
	getline(this->mCsvStream, data, ',');
	getline(this->mCsvStream, transactionField);
}

void DataAnalysis::readFile() {
	int units;
	std::string data;
	std::string transactionField;
	while (!(this->mCsvStream.eof())) {
		this->readLine(units, data, transactionField);
		this->insertIntoTree(units, data, transactionField);
	}
	std::cout << "Purchased: " << std::endl;
	this->mTreePurchased.inOrderTraversal();
	std::cout << "Sold: " << std::endl;
	this->mTreeSold.inOrderTraversal();
}

void DataAnalysis::insertIntoTree(int units, std::string data, std::string transactionField) {
	if (transactionField == "Sold") {
		this->mTreeSold.insert(data, units);
	}
	else if (transactionField == "Purchased") {
		this->mTreePurchased.insert(data, units);
	}
}

void DataAnalysis::trendAnalysis() {
	std::cout << "Purchased: " << std::endl << "Largest: ";
	(this->mTreePurchased.findLargest()).printData();
	std::cout << std::endl << "Smallest: ";
	(this->mTreePurchased.findSmallest()).printData();
	std::cout << std::endl << "Sold: " << std::endl << "Largest: ";
	(this->mTreeSold.findLargest()).printData();
	std::cout << std::endl << "Smallest: ";
	(this->mTreeSold.findSmallest()).printData();
}
