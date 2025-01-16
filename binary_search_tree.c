/*
Binary Search Tree
degree of the tree is two. so each parent can have max 2 children.
each left child has to be lesser than its root.
each right child has to be greater or equal to its root.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct bTree {
	int info;
	struct bTree* left;
	struct bTree* right;
}bTree;

bTree *root = NULL;

void insert(bTree *treeRoot, bTree *newNode);
void traverse(bTree* treeRoot);
bTree* search(bTree* treeRoot, int item);
bTree* delete(bTree* treeRoot, int item);
bTree* readNode();
int countNodes(bTree* treeRoot, int sum);

int main(void) {
	bTree* n, * a;
	int i, amount, choice;

	while (1) {
		printf( "1. insert a node\n"
				"2. delete a node\n"
				"3. list nodes\n"
				"4. search for a node\n"
				"5. count number of nodes\n"
				"6. exit\n"
				"Enter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {

		case 1:
			n = readNode();
			insert(root, n);
			break;

		case 2:
			printf("Enter node to be deleted");
			scanf("%d", i);
			a = delete(root, i);
			if (a != NULL)
				printf("Deleted..\n");
			else
				printf("Item to be deleted isn't found!\n");
			break;

		case 3:
			if (root != NULL)
				traverse(root);
			else
				printf("Tree is empty.\n");
			printf("\n");
			break;

		case 4:
			printf("Enter the number for searching: ");
			scanf("%d", &i);

			a = search(root, i);
			if (a == NULL)
				printf("The tree doesn't consist this value.\n");
			else
				printf("item found (%d)\n", a->info);
			break;

		case 5:
			amount = countNodes(root, 0);
			printf("Number of nodes in the tree is: %d\n", amount);
			break;

		case 6:
			return 0;
			break;

		default:
			return 0;
			break;
		}
	}

	return 0;
}


void insert(bTree* treeRoot, bTree *newNode) {
	//if tree is empty, then set the new node as root.
	if (treeRoot == NULL) {
		root = newNode;
	}
	else {
		if (newNode->info < treeRoot->info) {//if program goes in here, new number is lesser than root. go left.

			//go to left and if it's empty, then place the new number there.
			if (treeRoot->left == NULL) {
				treeRoot->left == newNode;
			}
			else {
				//if left isn't empty, assume that it's the root and try again. go until an empty left slot & place.
				insert(treeRoot->left, newNode);
			}
		}
		else {//if program comes here, it means that new number is greater than root. must go to right side here.
			
			//if right slot is empty then place new number there.
			if (treeRoot->right == NULL) {
				treeRoot->right = newNode;
			}
			else {//if right isn't empty, assume that right child is the new root and try again. until an empty slot.
				insert(treeRoot->right, newNode);
			}
		}
	}
}


//PRE-ORDER traversal function:
void traverse(bTree* treeRoot) {
	if (treeRoot != NULL) {
		printf("%d ", treeRoot->info);
		traverse(treeRoot->left);
		traverse(treeRoot->right);
	}
}


bTree* search(bTree* treeRoot, int item) {
	while ((treeRoot != NULL) && (treeRoot->info != item)) {
		//if the value of searched item is lesser than root, then go through left. otherwise go right.
		if (item < treeRoot->info)
			treeRoot = treeRoot->left;
		else
			treeRoot = treeRoot->right;
	}
	
	return treeRoot;
}


// q: node to be deleted  |  qa: parent of q
// find q & qa. if not found then exit.
// if q has 2 children. find the greatest value (s) in the left subtree. then copy s to the q.
// then delete the node having at most 1 child.
bTree* delete(bTree* treeRoot, int item) {
	bTree* q, * qa, * qc, * s, * sa;

	if (treeRoot == NULL)
		return NULL;

	q = treeRoot;
	qa = NULL;

	//search the item to be deleted (search function should be called)
	while ((q != NULL) && (q->info != item)) {
		qa = q;
		if (item < q->info)
			q = q->left;
		else
			q = q->right;
	}

	if (q == NULL) {
		printf("Item to be deleted couldn't found.\n");
		return NULL;
	}

	//if q is found and it has 2 children:
	if ((q->left != NULL) && (q->right != NULL)) {
		s = q->left;
		sa = q;

		//find item that has the max value in the left subtree.
		//so, take the rightmost node in the left subtree.
		while (s->right != NULL) {
			sa = s;
			s = s->right;
		}

		//copy s to the q
		q->info = s->info;
		q = s;
		qa = sa;
	}

	//now q has at most 1 child, and find it.
	if (q->left != NULL)
		qc = q->left;
	else
		qc = q->right;

	//delete q.
	if (q == treeRoot)
		root = qc;
	else {
		if (q == qa->left)
			qa->left = qc;
		else
			qa->right = qc;
	}

	free(q);
	return q;
}


//create a new node with taken info
bTree* readNode() {
	bTree* newNode;
	newNode = (bTree*)malloc(sizeof(bTree));

	if (newNode == NULL)
		return NULL;

	printf("Enter info: ");
	scanf("%d", &(newNode->info));

	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}


//count the number of nodes in the tree
int countNodes(bTree* treeRoot, int sum) {
	if (treeRoot == NULL)
		return sum;

	sum++;
	sum = countNodes(treeRoot->left, sum);
	sum = countNodes(treeRoot->right, sum);

	return sum;
}