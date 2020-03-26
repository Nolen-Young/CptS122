#include "Header.h";

int main(void) {
	char * str1 = "Hello World";
	char * str2 = "Computer Science";
	FILE * infile = fopen("letters.txt", "r");
	//reverse(str1);
	//printf("\n");
	//merge(str1, str2);
	count_letters(infile);

	fclose(infile);
}