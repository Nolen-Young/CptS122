#include "lab6.h"

void Complex::setRealPart(double n) {
	realPart = n;
}

void Complex::setImaginaryPart(double n) {
	imaginaryPart = n;
}

double Complex::getRealPart() {
	return realPart;
}

double Complex::getImaginaryPart() {
	return imaginaryPart;
}

void Complex::read(string input) {
	double realPart;
	double imaginaryPart;

	if (input.at(0) == '-') {

	} else {

	}
}

void Complex::print() {
	cout << realPart << "+" << imaginaryPart << "i" << endl;
}

Complex Complex::add(Complex newNum) {
	Complex result;
	result.realPart = newNum.realPart + realPart;
	result.imaginaryPart = newNum.imaginaryPart + imaginaryPart;
	return result;
}

Complex Complex::sub(Complex newNum) {
	Complex result;
	result.realPart = realPart - newNum.realPart ;
	result.imaginaryPart = imaginaryPart - newNum.imaginaryPart ;
	return result;
}

Complex operator+(Complex lhs, Complex rhs) {
	Complex result;
	result.setRealPart(lhs.getRealPart() + rhs.getRealPart());
	result.setImaginaryPart(lhs.getImaginaryPart() + rhs.getImaginaryPart());
	return result;
}

Complex operator-(Complex lhs, Complex rhs) {
	Complex result;
	result.setRealPart(lhs.getRealPart() - rhs.getRealPart());
	result.setImaginaryPart(lhs.getImaginaryPart() - rhs.getImaginaryPart());
	return result;
}

Complex add(Complex num1, Complex num2) {
	Complex result;
	result.setRealPart(num1.getRealPart() + num2.getRealPart());
	result.setImaginaryPart(num1.getImaginaryPart() + num2.getImaginaryPart());
	return result;
}

Complex sub(Complex num1, Complex num2) {
	Complex result;
	result.setRealPart(num1.getRealPart() - num2.getRealPart());
	result.setImaginaryPart(num1.getImaginaryPart() - num2.getImaginaryPart());
	return result;
}
