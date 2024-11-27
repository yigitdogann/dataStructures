#include <stdio.h>

void quicksort(int arr[], int left, int right);
void swap(int *high, int *low);
int partition(int arr[], int left, int right);

int main(void) {
	int arr[] = { 8,5,2,0,3,6,9,7,4,1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0, size-1);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

void quicksort(int arr[], int left, int right) {
	if (left < right) {
		//location of pivot. use partition to calculate
		int loc = partition(arr, left, right);

		quicksort(arr, left, loc - 1);
		quicksort(arr, loc + 1, right);
	}
}

int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int start = left;
	int end = right;
	while (start < end) {
		while (arr[start] <= pivot) {
			start++;
		}
		while (arr[end] > pivot) {
			end--;
		}
		if (start < end) {
			swap(&arr[start], &arr[end]);
		}
	}
	swap(&arr[left], &arr[end]);
	return end;
}

void swap(int* high, int* low) {
	int temp = *high;
	*high = *low;
	*low = temp;
}