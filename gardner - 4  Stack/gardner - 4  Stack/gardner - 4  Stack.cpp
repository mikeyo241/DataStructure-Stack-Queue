// Program Name:	Stack
// Chapter:			Chapter 4  - Stacks and Quesues
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
}Node, *NodePtr;


// ** Function Prototypes **

NodePtr getPhrase();
void print(NodePtr list);

int main()
{
	NodePtr phrase;
	cout << "     ** Part 1 Stack  **    \n";
	cout << "Please enter a phrase: ";
	phrase = getPhrase(); cout << endl;

	print(phrase);

	cout << endl << endl;  //Blank Line
	return 0;
}

NodePtr getPhrase() {
	NodePtr
		top = NULL,
		last = NULL,
		np;
	char
		c = getchar();

	while (c != '\n') {
		np = (NodePtr)malloc(sizeof(Node));
		np->ch = c;
		np->next = NULL;

		if (top == NULL) {
			top = np;
		}
		else {
			top = np;
			np->next = last;
		}
		last = np;
		c = getchar();
	}
	return top;
}

void print(NodePtr list) {
	if (list != NULL) {
		cout << list->ch;
		while (list->next != NULL) {
			list = list->next;
			cout << list->ch;
		}
	}
}