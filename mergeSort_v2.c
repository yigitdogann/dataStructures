/*
			[8,5,2,0,3,6,9,7,4,1]
			/                   \
		[8,5,2,0,3]               [6,9,7,4,1]
		/	  \                  /     \
              [8,5]   [2,0,3]	          [6,9]    [7,4,1]
              /  \ 	 /  \              /  \	  /    \
             [8] [5]  [2] [0,3]          [6]  [9]   [7]  [4,1]
                            / \                           / \
                           [0] [3]                      [4] [1]

divide: will work recursively, calls itself until there
is only one element left. and then, before going upward back
to the first recursion(first call), it performs the merge
function because divide will no more be worked.
(left<right is false, instead left=right)
*/
#include <stdio.h>

void mergesort(int arr[], int size);
void divide(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main(void) {
	int arr[] = { 8,5,2,0,3,6,9,7,4,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	mergesort(arr, n);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

void mergesort(int arr[], int size) {
	divide(arr, 0, size - 1);
}

void divide(int arr[], int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		divide(arr, left, mid);
		divide(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void merge(int arr[], int left, int mid, int right) {
	//l and r are temporary array size
	int l = mid - left + 1;
	int r = right - mid;

	//temporary arrays to sort
	int tempLeft[l];
	int tempRight[r];

	//filling the temp. arrays
	for (int i = 0; i < l; i++) {
		tempLeft[i] = arr[left + i];
	}
	for (int i = 0; i < r; i++) {
		tempRight[i] = arr[(mid + 1) + i];
	}

	/*i travers in main array, tl in tempLeft, tr in tempRight*/
	for (int tl = 0, tr = 0, i = left; i <= right; i++) {
		if ((tl < l) && (tr >= r || tempLeft[tl] <= tempRight[tr])) {
			arr[i] = tempLeft[tl];
			tl++;
		}
		else {
			arr[i] = tempRight[tr];
			tr++;
		}
	}
}