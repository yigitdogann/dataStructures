#include <stdio.h>
#include <stdlib.h>

void enqueue(int n);
void dequeue();
void reset();

typedef struct node {
	int data;
	struct node* nextPtr;
}node;

node* front = NULL, * last = NULL;

int main(void) {
	int choice = 0;

	while (choice != 4) {
		printf("1-enqueue\n2-dequeue\n3-reset\n4-print\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("what number do you want to add to your queue?\n");
			int n = 0; scanf("%d", &n);
			puts("");
			enqueue(n);
			break;
		case 2:
			dequeue();
			puts("");
			break;
		case 3:
			puts("");
			reset();
			break;
		default:
			break;
		}
	}

	node* printPtr = front;
	while (printPtr) {
		printf("%d ", printPtr->data);
		printPtr = printPtr->nextPtr;
	}

	return 0;
}

void enqueue(int n) {
	node* temp = NULL;
	temp = malloc(sizeof(node));

	if (temp == NULL) {
		printf("malloc error! memory is full.\n");
		return;
	}
	else {
		temp->data = n;
		temp->nextPtr = NULL;

		if (front == NULL) {
			front = temp;
			last = temp;
		}
		else {
			last->nextPtr = temp;
			last = temp;
		}
	}
}

void dequeue() {
	node* temp = NULL;
	if (front == NULL) {
		printf("queue is empty.\n");
		return;
	}
	else {
		temp = front;
		front = front->nextPtr;

		if (front == NULL) {
			last = NULL;
		}

		free(temp);
	}
}

void reset() {
	node* visitor;
	visitor = front;

	while (visitor) {
		front = front->nextPtr;
		free(visitor);
		visitor = front;
	}
	last = NULL;
}