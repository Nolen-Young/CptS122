#include "Header.h";

int reverse(char *str) {
	if (*str != '\0') {
		reverse(str + 1);
	}
	printf("%c", *str);
}

char * merge(char * str1, char * str2) {
	char * merged;
	merged = (char *)malloc(strlen(str1) + strlen(str2));
	char temp = "";
	int i = 0, j = 0, sorted_flag = 1, k = 0;


	for (i = 0; i < strlen(str1); i++) { // add str1 to array
		*(merged + i) = *(str1 + i);
	}
	for (i; i < strlen(str2) + strlen(str1); i++) { // add str2 to array
		*(merged + i) = *(str2 + j);
		j++;
	}

	
	while (sorted_flag) { // a very simple sorting algorithm
		k = 1;
		sorted_flag = 1;
		while (k < 50) {
			if (*(merged + k) > *(merged + k - 1)) {
				temp = *(merged + k);
				*(merged + k) = *(merged + k - 1);
				*(merged + k - 1) = temp;
				sorted_flag++;
			}
			k++;
		}
		if (sorted_flag == 1) {
			sorted_flag = 0;
			*(merged + k) = "\0";
		}
	}
	

	printf("%s", merged);
}

int count_letters(FILE * infile) {
	char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char count[26] = { 0 };
	char temp = 0;
	while (!feof(infile)) {
		temp = fgetc(infile);
		for (int i = 0; i < 26; i++) {
			if (temp == letters[i]) {
				count[i]++;
			}
		}
	}
	printf("%d", count[0]);
}
