#include "lab2.h"

Node * makeNode(Contact newData) {
	Node * newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->pNext = NULL;
		newNode->data = newData;
		return newNode;
	}
	
}

Boolean insertContactInOrder(Node ** pList, Contact newData) {
	Node * newNode = NULL, *pCur = NULL, *pPrev = NULL;
	newNode = makeNode(newData);
	pCur = *pList;

	if (newNode != NULL) {
		while (*pList != NULL && strcmp(newData.name, pCur->data.name) > 0) {
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		if (pPrev != NULL) {
			newNode->pNext = pCur;
			pCur = newNode;
			return TRUE;
		}
		else {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
}

Boolean deleteContact(Node ** pList, Contact searchContact) {
	Node * pCur = *pList, *pPrev = NULL;
	if (strcmp(pCur->data.name, searchContact.name) == 0) {
		*pList = pCur->pNext;
	}
	else {
		while (strcmp(pCur->data.name, searchContact.name) != 0) {
			pPrev = pCur;
			pCur = pCur->pNext;
			if (pCur->pNext == NULL) {
				return FALSE;
			}
		}
		pPrev->pNext = pCur->pNext;
	}
	free(pCur);
	return TRUE;
}

Boolean editContact(Node * pList, Contact searchContact) {
	Node * pCur = pList;
	char * newName = NULL;
	while (strcmp(pCur->data.name, searchContact.name) != 0) {
		pCur = pCur->pNext;
		if (pCur->pNext == NULL) {
			return FALSE;
		}
	}
	printf("Enter new name: ");
	scanf("%s", &newName);
	strcpy(pCur->data.name, newName);
	return TRUE;
}

Boolean loadContacts(FILE * infile, Node ** pList)
{
	return TRUE;
}

Boolean storeContacts(FILE * infile, Node * pList) {

	return TRUE;
}

void printList(Node * pList) {
	printf("-->");
	while (pList != NULL) {
		printf("%s-->", pList->data.name);
		pList = pList->pNext;
	}
	printf("\n");
}
