#ifndef PA1_H
#define PA1_H

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct duration {
	int minutes;
	int seconds;
} Durations;

typedef struct record {
	char artist[50];
	char album[50];
	char song[50];
	char genre[50];
	struct duration song_length;
	int times_played;
	int rating;
} Record;

typedef struct node {
	Record record;
	struct node *pNext;
	struct node *pPrevious;
} Node;

void print_menu(void);
void display(int mode, Node * pHead);
Node * makeNode(Record newRecord);
void load(Node ** pHead);
void store(Node ** pHead);
void edit(Node ** pHead);
void rate(Node ** pHead);
void play(Node ** pHead);
int delete(Node ** pList);
int insert(Node ** pHead);
void sort(Node ** pHead);
void shuffle(Node ** pHead);

#endif