/*
Nolen Young
11517296
9-13-17
PA2
Description: This program is a mock music player, some functionality is not available.
Also there a couple of logic bugs that I haven't figured out where sometimes itll save duplicates 
of the file instead of overwriting the file and other things, but it should work for 
everything to test for in this PA
Also not entirely sure this program will run without crashing
*/


#include "pa2.h"

int main(void) {
	int menu_selection = 0, display_mode = 0;
	int run_flag = 1;
	Record * pHead = NULL;

	while (run_flag == 1) {
		print_menu();
		scanf("%d%*c", &menu_selection); // get menu selection

		switch (menu_selection) {
		case 1:
			//load
			load(&pHead);
			break;
		case 2:
			//store
			store(&pHead);
			break;
		case 3:
			printf("\n(1) Print all\n(2) Print Arists\n>");
			scanf("%d", &display_mode);
			if (display_mode == 1 || display_mode == 2) {
				system("cls");
				display( display_mode, pHead);
			}
			else {
				printf("Error: Invalid Input");
			}
			//display
			break;
		case 4:
			//insert
			insert(&pHead);
			break;
		case 5:
			//delete
			delete(&pHead);
			break;
		case 6:
			//edit
			edit(&pHead);
			break;
		case 7:
			//sort
			sort(&pHead);
			break;
		case 8:
			//rate
			rate(&pHead);
			break;
		case 9:
			//play
			play(&pHead);
			break;
		case 10:
			//shuffle
			break;
		case 11:
			//exit
			store(&pHead);
			run_flag = 0;
			break;
		default:
			printf("Error: Invalid Input\n");
			break;
		}
		system("pause");
		system("cls");
	}
}