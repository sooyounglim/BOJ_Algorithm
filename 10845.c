#include <stdio.h>
#include <string.h>

int main(void) {
	int n, i;
	int element;
	int front = 0, rear = 0, count = 0;
	int queue[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		char s[10];
		scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			scanf("%d", &element);
			queue[rear] = element;
			rear++;
			count++;
		}
		else if (strcmp(s, "pop") == 0) {
			if (front == rear)
				printf("-1\n");
			else {
				printf("%d\n", queue[front]);
				front++;
				count--;
			}
		}
		else if (strcmp(s, "size") == 0)
			printf("%d\n", count);
		else if (strcmp(s, "empty") == 0) {
			if (front == rear)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(s, "front") == 0){
			if (front == rear)
				printf("-1\n");
			else
				printf("%d\n", queue[front]);
		}
		else if (strcmp(s, "back") == 0) {
			if (front == rear)
				printf("-1\n");
			else
				printf("%d\n", queue[rear-1]);
		}
	}
	return 0;
}