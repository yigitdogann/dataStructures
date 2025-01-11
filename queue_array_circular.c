#include <stdio.h>
#define N 5

int Q[N];
int front, last, counter = 0;

void enqueue(int n);
void dequeue();
void reset();

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

void enqueue(int n) {
	if (counter >= N) {
		printf("queue is full.\n");
		return;
	}
	else {
		Q[last] = n;
		last = (last + 1) % N;//hence it'll wrap around N. goes back to zero if reaches N
		counter++;
		return;
	}
}
void dequeue() {
	if (counter == 0) {
		printf("queue is empty.\n");
		return;
	}
	else {
		front = (front + 1) % N;
		counter--;
		return;
	}
}
void reset() { last = 0; }