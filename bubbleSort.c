#include <stdio.h>

void bubblesort(int*arr, int n);

int main(void) {
	int arr[] = { 8,5,2,0,3,6,1,4,7,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

void bubblesort(int* arr, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[j] < arr[j-1]) {
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}