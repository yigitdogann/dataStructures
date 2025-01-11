#include <stdio.h>
#define N 10

int Q[N];
int last = 0;

void enqueue(int x);
void dequeue();
void reset() { last = 0; }

int main(void) {
	int choice = 0;

	while (choice != 4) {
		printf("1-enqueue\n2-dequeue\n3-reset\n4-print\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("what number do you want to add to your queue?\n");
			int n = 0; scanf("%d", &n);
			puts("");
			enqueue(n);
			break;
		case 2:
			dequeue();
			puts("");
			break;
		case 3:
			puts("");
			reset();
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d - ", Q[i]);
	}

	return 0;
}

void enqueue(int x) {
	if (last == N) {
		printf("queue is full, cannot insert!");
		return;
	}
	else {
		Q[last] = x;
		last++;
		return;
	}
}

void dequeue() {
	if (last == 0) {
		printf("queue is empty, cannot delete!");
		return;
	}
	else {
		for (int i = 0; i < last; i++)
			Q[i - 1] = Q[i];
		last--;
		return;
	}
}