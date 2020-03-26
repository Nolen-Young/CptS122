#include "lab6.h"

int main(void) {
	Complex num1, num2, num3;

	num1.setRealPart(1);
	num1.setImaginaryPart(2);
	num2.setRealPart(3);
	num2.setImaginaryPart(4);

	num3 = num1 + num2;
	num3.print();
	return 1;
}