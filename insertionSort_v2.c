#include <stdio.h>

void insertionSort(int b[], int n);//n: lenght of array

int main(void) {
	printf("\t\tInsertion Sort\n");

	int a[] = { 11,58,94,35,66,1,33,85,73 };

	puts("Before function: ");
	for (int i = 0; i < (sizeof(a) / sizeof(int)); i++) {
		printf("%d ", a[i]);
	}

	puts(""); puts("");

	insertionSort(a, (sizeof(a) / sizeof(int)));

	puts("After function: ");
	for (int i = 0; i < (sizeof(a) / sizeof(int)); i++) {
		printf("%d ", a[i]);
	}

	return 0;
}

void insertionSort(int b[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = b[i];
		int j = i - 1;

		while (j>=0 && temp < b[j]) {
			b[j + 1] = b[j];
			j--;
		}
		
		b[j+1] = temp;
	}
}