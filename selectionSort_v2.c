#include <stdio.h>

void myFunction(int b[], int size);

int main(void) {
	puts("selection sort");
	int a[5] = {2,0,3,0,5};

	myFunction(a, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}

void myFunction(int b[], int size) {
	for (int i = 0; i < (size - 1); i++) {
		int indexMin = i;
		for (int j = i; j < size; j++) {
			if (b[j] < b[indexMin]) {
				indexMin = j;
			}
		}
		if (indexMin != i) {
			int temp = b[i];
			b[i] = b[indexMin];
			b[indexMin] = temp;
		}
	}
}