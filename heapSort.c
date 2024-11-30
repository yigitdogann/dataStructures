#include <stdio.h>

void printarray(int arr[], int n);
void heapsort(int arr[], int n);
void heapify(int arr[], int n, int i);
void swap(int* xp, int* yp);

int main(void) {
	int arr[] = { 2,5,0,3,1,9,7 };
	printf("Given array is: \n");
	int size = sizeof(arr) / sizeof(arr[0]);

	printarray(arr, size);
	heapsort(arr, size);

	printf("\n\nSorted array is: \n");
	printarray(arr, size);

	return 0;
}

//main function for heap sort
void heapsort(int arr[], int n) {
	//build max heap
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify(arr, n, i);

	//heap sort
	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		//heapify again to get highest element to root
		heapify(arr, i, 0);
	}
}

void heapify(int arr[], int n, int i) {
	//find largest among root - left child - right child

	//initialize largest as root
	int largest = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	//if left child is larger than root
	if (left<n && arr[left]>arr[largest])
		largest = left;

	//if right child is larger than largest so far
	if (right<n && arr[right]>arr[largest])
		largest = right;

	//swap and continue heapifying if root isn't largest
	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		//heapify the affected sub-tree recursively
		heapify(arr, n, largest);
	}
}

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printarray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}