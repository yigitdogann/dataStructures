#include <stdio.h>
#define M 15//degree of tree
#define x 10//degree of tree
#define y 200//number of nodes(for array based)

//creating a tree by using a pointer for each child
typedef struct tree_m{
	int info;
	char message[100];
	struct tree_m* P[M];//for each child, there's a pointer
}tree_m;

tree_m* root1 = NULL;


//creating a tree by using only two pointers.
typedef struct tree_n {
	int info;
	char message[100];
	struct tree_n* c;//pointer to a child
	struct tree_n* s;//pointer to a sibling
}tree_n;

tree_n* root2 = NULL;


//creating binary tree. we only need 2 pointers which point max. 2 children
typedef struct bTree {
	int info;
	char message[100];
	struct bTree* left;
	struct bTree* right;
}bTree;

bTree* root3 = NULL;


//creating an array based tree.
typedef struct tree_x {
	int info;
	char message[100];
	int P[x];//store indices of child nodes
}tree_x;

tree_x T[y];//array which stores the data


//creating a tree with only 2 pointers by using array
typedef struct tree_x2 {
	int info;
	char message[100];
	int c;//array index of child
	int s;//array index of sibling
}tree_x2;

tree_x2 D[y];


//creating a binary tree with using array
//index of root = 0
//         left child of node i = (2 * i) + 1
//         right child of node i = (2 * i) + 2
typedef struct bTree2 {
	int info;
	char message[100];
}bTree2;

bTree2 E[y];

int main(void) {
	
	return 0;
}