#include <stdio.h>
#define SIZE 9

void selectionSort(int arr[], int n);

int main(void) {
	printf("\t\tSelection_Sort\n");

	int arr[SIZE] = { 1,8,6,5,4,3,7,9,2 };

	puts("Before function:");
	for (int i = 0; i < SIZE; i++) {
		printf("%d", arr[i]);
	}

	puts("");
	puts("");
	
	selectionSort(arr, SIZE);
	
	puts("After function:");
	for (int i = 0; i < SIZE; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < (n - 1); i++) {
		int minIndex = i;

		for (int j = (i + 1); j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		if (i != minIndex) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}