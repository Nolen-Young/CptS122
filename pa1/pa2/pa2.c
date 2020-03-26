#include "pa2.h"

void print_menu(void) {
	printf("\
(1) Load\n\
(2) Store\n\
(3) Display\n\
(4) Insert\n\
(5) Delete\n\
(6) Edit\n\
(7) Sort\n\
(8) Rate\n\
(9) Play\n\
(10) Shuffle\n\
(11) Exit\n\
>");
}

void display(int mode, Node * pHead){
	Node * pCur = NULL;

	if (pHead != NULL) {
		if (mode == 1) { // print all
			pCur = pHead;

			while (pCur->pNext != NULL) {
				printf("%s\n%s\n%s\n%s\n%d:%d\nTimes Played: %d\nRating: %d\n\n",
					pCur->record.artist, pCur->record.album, pCur->record.song, pCur->record.genre, pCur->record.song_length.minutes, pCur->record.song_length.seconds, pCur->record.times_played, pCur->record.rating);
				pCur = pCur->pNext;
			}
		}
		else { // print artist
			char artist[50] = { NULL };
			printf("Enter artist (case sensitive): ");
			scanf("%s", &artist);
			pCur = pHead;

			while (pCur->pNext != NULL) {
				if (strcmp(artist, pCur->record.artist) == 0) {
					printf("%s\n%s\n%s\n%s\n%d:%d\nTimes Played: %d\nRating: %d\n\n",
						pCur->record.artist, pCur->record.album, pCur->record.song, pCur->record.genre, pCur->record.song_length.minutes, pCur->record.song_length.seconds, pCur->record.times_played, pCur->record.rating);
				}
				pCur = pCur->pNext;
			}
		}
	}
	else {
		printf("You must load in a list to display.\n");
	}
}

Node * makeNode(Record newRecord) {
	Node * newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->pNext = NULL;
		newNode->pPrevious = NULL;
		newNode->record = newRecord;
		return newNode;
	}
}

void load(Node ** pHead) {
	FILE * infile = NULL;
	infile = fopen("musicPlayList.csv", "r");

	if (infile == NULL) {
		printf("Could not open file");
		system("pause");
	}

	char line[100] = {NULL},
		copyLine[100] = { NULL };
	
	char artist[50] = { NULL },
		album[50] = { NULL },
		song[50] = { NULL },
		genre[50] = { NULL };

	int times_played = 0,
		rating = 0,
		minutes = 0,
		seconds = 0;


	while (!feof(infile)) {
		Node * newNode = NULL;

		Record * newRecord = NULL;
		newRecord = (Record*)malloc(sizeof(Record));

		fgets(line, 99, infile); // get the second line - fitbit data
		strcpy(copyLine, line); // preserve the original line

		//store all of the information from the line into variables
		strcpy(artist, strtok(copyLine, ","));
		strcpy(album, strtok(NULL, ",")); 
		strcpy(song, strtok(NULL, ","));
		strcpy(genre, strtok(NULL, ","));
		minutes = atof(strtok(NULL, ":"));
		seconds = atof(strtok(NULL, ","));
		times_played = atof(strtok(NULL, ","));
		rating = atof(strtok(NULL, ","));

		//put information into a Records struct
		strcpy(newRecord->artist, artist);
		strcpy(newRecord->album, album);
		strcpy(newRecord->song, song);
		strcpy(newRecord->genre, genre);
		newRecord->song_length.minutes = minutes;
		newRecord->song_length.seconds = seconds;
		newRecord->times_played = times_played;
		newRecord->rating = rating;

		//insert struct into the front of the list
		newNode = makeNode(*newRecord);
		if (*pHead == NULL) {
			(*pHead) = newNode;
		}
		else {
			newNode->pNext = *pHead;
			(*pHead)->pPrevious = newNode;
			(*pHead) = newNode;
		}
	}
	fclose(infile);
}

void store(Node ** pHead) {
	FILE * infile = NULL;
	infile = fopen("musicPlayList.csv", "w");

	Node * pCur = NULL;
	pCur = (*pHead);
	do {
		fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", 
			pCur->record.artist, pCur->record.album, pCur->record.song, pCur->record.genre, pCur->record.song_length.minutes, pCur->record.song_length.seconds, pCur->record.times_played, pCur->record.rating);
		pCur = pCur->pNext;
	} while (pCur->pNext != NULL);

	// the loop cannot print the last song of a file, this hardcodes the program to print the last song.
	fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d",
		pCur->record.artist, pCur->record.album, pCur->record.song, pCur->record.genre, pCur->record.song_length.minutes, pCur->record.song_length.seconds, pCur->record.times_played, pCur->record.rating);

	fclose(infile);
}

void edit(Node ** pHead) {
	Node * pCur = NULL;
	pCur = (*pHead);

	char target_artist[50],
		target_song[50],
		change_char[50] = { NULL };
	int counter = 0,
		selection = 0,
		change_int = 0;

	int run_flag = 1;

	// get artist name
	printf("Enter artist's name (case sensitive): ");
	gets(target_artist);

	// count how many songs exist by that artist
	while (pCur->pNext != NULL) {
		if (strcmp(pCur->record.artist, target_artist) == 0)
			counter++;
		pCur = pCur->pNext;
	}

	//reset pCur to the beginning of the list
	pCur = (*pHead);

	//perform appropriate algorithm depending on number 
	if (counter == 1) {
		// find artist
		while (pCur->pNext != NULL) {
			if (strcmp(pCur->record.artist, target_artist) == 0)
				break;
			pCur = pCur->pNext;
		}
		// prompt for change and perform change
		while (run_flag == 1) {
			printf("\nSelect something to modify:\n(1) Artist\n(2) Album\n(3) Song Name\n(4) Genre\n(5) Minutes\n(6) Seconds\n(7) Times played\n(8) Rating\n(9) Exit\n>");
			scanf("%d%*c", &selection);

			switch (selection) {
			case 1 :
				//artist
				printf("Enter new data for artist: ");
				gets(change_char);
				strcpy(pCur->record.artist, change_char);
				break;
			case 2:
				//album
				printf("Enter new data for album: ");
				gets(change_char);
				strcpy(pCur->record.album, change_char);
				break;
			case 3:
				// song
				printf("Enter new data for song name: ");
				gets(change_char);
				strcpy(pCur->record.song, change_char);
				break;
			case 4:
				// genre
				printf("Enter new data for genre: ");
				gets(change_char);
				strcpy(pCur->record.genre, change_char);
				break;
			case 5:
				//minutes
				printf("Enter new data for minutes: ");
				scanf("%d", &change_int);
				pCur->record.song_length.minutes = change_int;
				break;
			case 6:
				//seconds
				printf("Enter new data for seconds: ");
				scanf("%d", &change_int);
				pCur->record.song_length.seconds = change_int;
				break;
			case 7:
				//times played
				printf("Enter new data for times played: ");
				scanf("%d", &change_int);
				pCur->record.times_played = change_int;
				break;
			case 8:
				//rating
				printf("Enter new data for rating: ");
				scanf("%d ", &change_int);
				pCur->record.rating = change_int;
				break;
			case 9:
				//exit
				run_flag = 0;
				break;
			default:
				printf("Invalid selection\n");
				break;
			}
		}
	}
	else if (counter > 1) {
		// prompt for song
		printf("Multiple songs by that artist exist, enter song name: ");
		gets(target_song);

		// find song name
		while (pCur->pNext != NULL) {
			if (strcmp(pCur->record.song, target_song) == 0)
				break;
			pCur = pCur->pNext;
		}

		while (run_flag == 1) {
			printf("\nSelect something to modify:\n(1) Artist\n(2) Album\n(3) Song Name\n(4) Genre\n(5) Minutes\n(6) Seconds\n(7) Times played\n(8) Rating\n(9) Exit\n>");
			scanf("%d%*c", &selection);

			switch (selection) {
			case 1:
				//artist
				printf("Enter new data for artist: ");
				gets(change_char);
				strcpy(pCur->record.artist, change_char);
				break;
			case 2:
				//album
				printf("Enter new data for album: ");
				gets(change_char);
				strcpy(pCur->record.album, change_char);
				break;
			case 3:
				// song
				printf("Enter new data for song name: ");
				gets(change_char);
				strcpy(pCur->record.song, change_char);
				break;
			case 4:
				// genre
				printf("Enter new data for genre: ");
				gets(change_char);
				strcpy(pCur->record.genre, change_char);
				break;
			case 5:
				//minutes
				printf("Enter new data for minutes: ");
				scanf("%d", &change_int);
				pCur->record.song_length.minutes = change_int;
				break;
			case 6:
				//seconds
				printf("Enter new data for seconds: ");
				scanf("%d", &change_int);
				pCur->record.song_length.seconds = change_int;
				break;
			case 7:
				//times played
				printf("Enter new data for times played: ");
				scanf("%d", &change_int);
				pCur->record.times_played = change_int;
				break;
			case 8:
				//rating
				printf("Enter new data for rating: ");
				scanf("%d", &change_int);
				pCur->record.rating = change_int;
				break;
			case 9:
				//exit
				run_flag = 0;
				break;
			default:
				printf("Invalid selection\n");
				break;
			}
		}
	}
	else { // counter == 0
		printf("No songs exist by that artist\n");
	}
}

void rate(Node ** pHead) {
	char target_song[50] = { NULL };
	Node * pCur = NULL;
	pCur = (*pHead);
	int rating = 0;

	printf("Enter the song you would like to rate: ");
	gets(target_song);

	while (pCur->pNext != NULL) {
		if (strcmp(pCur->record.song, target_song) == 0)
			break;
		pCur = pCur->pNext;
	}
	printf("What would you like to rate the song: ");
	scanf("%d%*c", &rating);
	pCur->record.rating = rating;
}

void play(Node ** pHead) {
	Node * pCur = NULL;
	pCur = (*pHead);
	char target_song[100] = { NULL };

	printf("Enter the song you would like to play: ");
	gets(target_song);

	// sets pCur to the song we would like to start with
	while (pCur->pNext != NULL) {
		if (strcmp(pCur->record.song, target_song) == 0)
			break;
		pCur = pCur->pNext;
	}

	while (pCur->pNext != NULL) {
		printf("Now playing: %s by %s", pCur->record.song, pCur->record.artist);
		Sleep(5000);
		system("cls");
		pCur = pCur->pNext;
	}
	// this is so the last song of the list plays
	printf("Now playing: %s by %s", pCur->record.song, pCur->record.artist);
	Sleep(5000);
	system("cls");
}

int insert(Node ** pHead) {
	Node * pCur = (*pHead),
		*newNode = NULL;
	char artist[50] = "",
		album[50] = "",
		song[50] = "",
		genre = "";
	int minutes = 0,
		seconds = 0,
		times_played = 0,
		rating = 0;

	Record * newRecord = NULL;
	newRecord = (Record*)malloc(sizeof(Record));

	printf("Artist: ");
	gets(artist);
	printf("Album: ");
	gets(album);
	printf("Song: ");
	gets(song);
	printf("Genre: ");
	gets(genre);
	printf("Minutes: ");
	scanf("%d", &minutes);
	printf("Seconds: ");
	scanf("%d", &seconds);
	printf("Rating: ");
	scanf("%d", &rating);

	if (newRecord != NULL) {
		strcpy(newRecord->artist, artist);
		strcpy(newRecord->album, album);
		strcpy(newRecord->song, song);
		strcpy(newRecord->genre, genre);
		newRecord->song_length.minutes = minutes;
		newRecord->song_length.seconds = seconds;
		newRecord->rating = rating;

		newNode = makeNode(*newRecord);
		newNode->pNext = pCur;
		pCur->pPrevious = newNode;
		*pHead = newNode;
		return 1;

	} else {
		return 0;
	}
}

int delete(Node ** pList) {
	Node * pCur = *pList, *pPrev = NULL;
	char searchName[50] = "";
	printf("Enter a song title to delete: ");
	gets(searchName);

	if (strcmp(pCur->record.song, searchName) == 0) {
		*pList = pCur->pNext;
		pCur->pNext->pPrevious = NULL;
	}
	else {
		while (strcmp(pCur->record.song, searchName) != 0) {
			pPrev = pCur;
			pCur = pCur->pNext;
			if (pCur->pNext == NULL) {
				printf("Song not found\n");
				return 0;
			}
		}
		pPrev->pNext = pCur->pNext;
		pCur->pNext->pPrevious = pPrev;
	}
	free(pCur);
	return 1;
}

void sort(Node ** pHead) {
	int selection = 0;

	int swapped, i;
	Node *ptr1;
	Node *lptr = NULL;
	Node * pCur = (*pHead);
	Node * pTemp = NULL;

	printf("1. Sort based on artist (A-Z)\n2. Sort based on album title(A - Z)\n3. Sort based on rating(1 - 5)\n4. Sort based on times played(largest - smallest)\n>");
	scanf("%d", &selection);

	if (*pHead == NULL) // check for empty list;
		return;

	switch (selection) {
	case 1:
		do {
			swapped = 0;
			ptr1 = (*pHead);

			while (ptr1->pNext != lptr) {
				if (ptr1->record.artist[0] > ptr1->pNext->record.artist[0]) {
					pTemp = ptr1->pNext;
					pTemp->pPrevious = ptr1->pPrevious;
					ptr1->pPrevious = pTemp;
					ptr1->pNext = pTemp->pNext;
					pTemp->pNext = ptr1;

					swapped = 1;
				}
				ptr1 = ptr1->pNext;
			}
			lptr = ptr1;
		} while (swapped);
		break;
	case 2:
		do {
			swapped = 0;
			ptr1 = (*pHead);

			while (ptr1->pNext != lptr) {
				if (ptr1->record.album[0] > ptr1->pNext->record.album[0]) {
					pTemp = ptr1->pNext;
					pTemp->pPrevious = ptr1->pPrevious;
					ptr1->pPrevious = pTemp;
					ptr1->pNext = pTemp->pNext;
					pTemp->pNext = ptr1;

					swapped = 1;
				}
				ptr1 = ptr1->pNext;
			}
			lptr = ptr1;
		} while (swapped);
		break;
	case 3:
		do {
			swapped = 0;
			ptr1 = (*pHead);

			while (ptr1->pNext != lptr) {
				if (ptr1->record.rating > ptr1->pNext->record.rating) {
					pTemp = ptr1->pNext;
					pTemp->pPrevious = ptr1->pPrevious;
					ptr1->pPrevious = pTemp;
					ptr1->pNext = pTemp->pNext;
					pTemp->pNext = ptr1;

					swapped = 1;
				}
				ptr1 = ptr1->pNext;
			}
			lptr = ptr1;
		} while (swapped);
		break;
	case 4: 
		do {
			swapped = 0;
			ptr1 = (*pHead);

			while (ptr1->pNext != lptr){
				if (ptr1->record.times_played > ptr1->pNext->record.times_played){
					pTemp = ptr1->pNext;
					pTemp->pPrevious = ptr1->pPrevious;
					ptr1->pPrevious = pTemp;
					ptr1->pNext = pTemp->pNext;
					pTemp->pNext = ptr1;
					
					swapped = 1;
				}
				ptr1 = ptr1->pNext;
			}
			lptr = ptr1;
		} while (swapped);
		break;
	}
}

void shuffle(Node ** pHead) {
	int play_order[1000] = { 0 },
		counter = 0,
		cur = 1,
		position_in_order = 0,
		movement = 0;
	Node * pCur = (*pHead);

	while (pCur->pNext != NULL) {
		counter++;// count how many items are in the list
		pCur = pCur->pNext;
	}
	pCur = (*pHead); // reset pCur to the beginning of the list

	// generate random numbers for the shuffle playlist
	srand(time(NULL));
	int r = (rand() % counter) + 1;
	for (int i = 0; i < counter; i++) {
		play_order[i] = r;
		r = (rand() % counter) + 1;
	}

	for (int i = 0; i < counter; i++) {
		movement = play_order[i] - cur;
		if (movement > 0) {
			for (int j = 0; j < movement; j++) {
				pCur = pCur->pNext;
			}
		}
		else if (movement < 0) {
			movement = abs(movement);
			for (int j = 0; j < movement; j++) {
				pCur = pCur->pPrevious;
			}
		}
		printf("Now playing: %s by %s", pCur->record.song, pCur->record.artist);
		Sleep(5000);
		system("cls");
	}
}
