#include <stdio.h>
#include <stdlib.h>//for malloc

typedef struct node {
	int a;
	struct node* nextPtr;
}node;

node *head = NULL, *tail = NULL;

void add(void);
void print(void);
void delete(void);
void instructions(void);

int main(void) {
	printf("\t\tlinked-list\n\n"); 
	printf("how many items r u gonna add?");
	
	int n = 0; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		add();
	}
	print();

	delete();
	print();

	return 0;
}

void add() {
	printf("enter the value");
	int x = 0;  scanf("%d", &x);

	//create a pointer for new node.
	node* temp;
	//give memory's address to the pointer. convert void return type to node*
	temp = (node*)malloc(sizeof(node));

	//check if there's no problem while allocating memory to new node
	if (temp != NULL) {
		temp->a = x;
		temp->nextPtr = NULL;
	}

	if (head == NULL) {
		head = temp;
		tail = head;
	}
	else {
		tail->nextPtr = temp;
		tail = temp;
	}
}

void print(void) {
	node* traverser = head;
	while (traverser != NULL) {
		printf("%d->", traverser->a);
		traverser = traverser->nextPtr;
	}
}

void delete(void) {
	printf("which number r u gonna delete");
	int n = 0; scanf("%d", &n);

	node* traverser = head;
	
	head->a;
	while (n != traverser->nextPtr->a) {
		traverser = traverser->nextPtr;
	}

	if ((traverser->nextPtr->a)==n) {
		node* temp = traverser->nextPtr;
		traverser->nextPtr = traverser->nextPtr->nextPtr;
		free(temp);
	}
	else {
		printf("not found");
	}

}
