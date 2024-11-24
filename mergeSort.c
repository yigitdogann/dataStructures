/*
this code will not be able to work in visual studio.
because of the C99 VLA(variable lenght arrays).
you can use online or any other compilers which use VLA.
*/
#include <stdio.h>

void mergeSort(int b[], int size);
void divide(int b[], int l, int r);
void merge(int b[], int l, int m, int r);

int main(void) {
	printf("\t\tMerge Sort Algorithm\n");

	int myArray[10] = {0,5,2,9,1,4,7,8,3,6};

	puts("Before function:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", myArray[i]);
	}

	puts(""); puts("");

	mergeSort(myArray, 10);

	puts("After function:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", myArray[i]);
	}
	return 0;
}

void mergeSort(int arr[], int size) {
	divide(arr, 0, (size-1));
}

/*divide algorithm works recursively,
calls itself until there's only 1 element left*/
void divide(int arr[], int l, int r) {
	
	if(l < r){
		int m = (l + (r - 1)) / 2;//m is midpoint left(1)+right(r)/2
		divide(arr, l, m);
		divide(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r) {
	//length calculation for temporary arrays
	int leftLength = m - l + 1;
	int rightLength = r - m;

	//temporary arrays for merge steps
	int tempLeft[leftLength];
	int tempRight[rightLength];

	//filling the temporary arrays
	for (int i = 0; i < leftLength; i++) {
		tempLeft[i] = arr[l + i];
	}
	for (int i = 0; i < rightLength; i++) {
		tempRight[i] = arr[m + 1 + i];
	}

	/*k keeps track of our place in original array.
	we want to traverse in the array (l to r)
	i and j keeps track of tempLeft and tempRight respectively.*/
	for (int i = 0, j = 0, k = l; k <= r; k++) {

		if ((i < leftLength) && (j >= rightLength || tempLeft[i] <= tempRight[j])) {
			arr[k] = tempLeft[i];
			i++;
		}
		else {
			arr[k] = tempRight[j];
			j++;
		}
	}
}

