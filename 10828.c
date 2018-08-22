#include <stdio.h>
#include <string.h>

int main(void) {
	int n, i;
	int element;
	int top = -1;
	int stack[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		char s[10];
		scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			scanf("%d", &element);
			stack[++top] = element;
		}
		else if (strcmp(s, "pop") == 0) {
			if (top < 0)
				printf("-1\n");
			else
				printf("%d\n", stack[top--]);
		}
		else if (strcmp(s, "size") == 0)
			printf("%d\n", top + 1);
		else if (strcmp(s, "empty") == 0) {
			if (top < 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(s, "top") == 0) {
			if (top < 0)
				printf("-1\n");
			else
				printf("%d\n", stack[top]);
		}
	}
	return 0;
}