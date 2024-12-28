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

int main(void) {
	printf("push-1\npop-2\nend-3\n->");
	int decide; scanf("%d", &decide);

	while (decide != 3) {
		switch (decide)
		{
		case 1:
			printf("enter a number: ");
			int n = scanf("%d", &n);
			push(n);
			break;
		case 2: 
			pop();
			break;
		case 3:
			return 0;
			break;
		default: 
			break;
		}
		puts("");
		printf("push-1\npop-2\nend-3\n->");
		scanf("%d", &decide);

		printer();
	}
	return 0;
}

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

void printer() {
	stack* traverser = sp;
	while (traverser!=NULL) {

	}
}