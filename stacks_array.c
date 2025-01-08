/*
*	STACKS - LIFO
* Last In First Out
* Implemented by arrays.
-An example of text reverser-
*/
#include <stdio.h>
#define N 500 //size of the stack array

char S[N];
int sp = 0;//stack pointer for *inserting index*

void push(char x);
char pop();
void reset();
int top();
int size();

int main(void) {
	char c;

	printf("Your text: \n\t");
	while ((c = fgetchar()) != '\n')
		push(c);


	printf("Reversed: \n\t");
	while (sp > 0)
		printf("%c", pop());

	puts("");
	return 0;
}

void push(char x) {
	if (sp >= N) {
		printf("Stack is full, insertion failed!");
		return;
	}
	else {
		S[sp] = x;
		sp++;
	}
}

char pop() {
	if (sp <= 0) {
		printf("Stack is empty, cannot delete anymore.");
		return;
	}
	else {
		sp--;
		return S[sp];
	}
}

//returns the index of last added element. top item of the stack
int top() { return (sp - 1); }

int size() { return sp; }

void reset() { sp = 0; } //acts like array is empty but it isn't. works fine