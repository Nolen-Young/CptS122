#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Complex {
private:
	double realPart;
	double imaginaryPart;

public:
	void setRealPart(double n);
	void setImaginaryPart(double n);
	double getRealPart();
	double getImaginaryPart();
	void read(string input);
	void print();
	Complex add(Complex newNum);
	Complex sub(Complex newNum);
};

Complex operator+(Complex lhs, Complex rhs);
Complex operator-(Complex lhs, Complex rhs);
Complex add(Complex num1, Complex num2);
Complex sub(Complex num1, Complex num2);

