// Program Name:	Part 2 Queue
// Chapter:			Chapter 4  - Stacks and Queues
// Programmer:		Michael A Gardner
// Date:			4 July 2016
// Description:		
//					

#include "stdafx.h"
#include <iostream>

using namespace std;


//  ** Node Structure **
typedef struct node {
	char ch;
	struct node *next;
	struct node *prev;
}Node, *NodePtr;


// ** Function Prototypes **
void print(NodePtr list);
NodePtr getPhrase();

int main()
{
	NodePtr phrase;
	cout << "      ** PART 2 - QUEUE ** \n\n";
	cout << "Enter a Phrase: ";
	phrase = getPhrase();
	cout << endl;
	print(phrase);

	cout << endl << endl;  //Blank Line
	return 0;
}

NodePtr getPhrase() {
	NodePtr
		top = NULL,
		last = NULL,
		tail = NULL,
		np;
	char
		c = getchar();

	while (c != '\n') {
		np = (NodePtr)malloc(sizeof(Node));
		np->ch = c;
		np->next = NULL;
		np->prev = NULL;

		if (top == NULL) {
			top = np;
			tail = np;
		}
		else {
			top = np;
			np->next = last;
			last->prev = np;
		}
		last = np;
		c = getchar();
	}
	return tail;
}

void print(NodePtr list) {
	if (list != NULL) {
		cout << list->ch;
		while (list->prev != NULL) {
			list = list->prev;
			cout << list->ch;
		}
	}
}