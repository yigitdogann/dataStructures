/*	
*	STACKS - LIFO
* Last In First Out
* Implemented by pointers.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int data;
	struct stack* next;
}stack;

stack* sp = NULL;//top item of stack.

void push(int x);
void pop();
void printer();
void reset();
stack* topAddress();

int main(void) {
	printf("push-1\npop-2\nend-3\n->");
	int decide; scanf("%d", &decide);

	while (decide != 3) {
		switch (decide)
		{
		case 1:
			printf("enter a number: ");
			int n; scanf("%d", &n);
			push(n);
			break;
		case 2: 
			pop();
			break;
		case 3:
			break;
		default: 
			break;
		}

		printf("\npush-1\npop-2\nend-3\n->");
		scanf("%d", &decide);
	}

	printer();
	reset(); //tested - works fine.

	return 0;
}

//adds new items to stack. always to the top (or beginning). checks malloc error before adding.
void push(int x) {
	stack* p;
	p = (stack*)malloc(sizeof(stack));

	if (p == NULL) {
		printf("memory allocation error!");
		return;
	}
	else {
		p->data = x;
		p->next = sp;
		sp = p;
	}
}

//deletes the last added item (top). re-arranges the top pointer before deleting
void pop() {
	stack* p;

	if (sp == NULL) {
		printf("Stack is empty.");
		return;
	}
	else {
		p = sp;
		sp = sp->next;
		free(p);
		return;
	}
}

//prints the stack, visitor is a pointer which traverse until NULL
void printer() {
	stack* visitor = sp;
	printf("\nTOP-->");
	while (visitor!=NULL) {
		printf("\t|  %d  |\n", visitor->data);
		visitor = visitor->next;
	}

	printf("\nTop item's address = %p\n", topAddress());
}

//sets the "top pointer" to the next, and delete until NULL
void reset() {
	stack* p= NULL;
	while (sp != NULL) {
		p = sp;
		sp = sp->next;
		free(p);
	}
}

//returns the top item's address. Actually the address of the stack
stack* topAddress() {
	return sp;
}