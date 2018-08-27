#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void makeheap(int num[], int root, int n) {
	int child, temp;
	temp = num[root];
	child = 2 * root;

	while (child <= n) {
		if ((child < n) && (num[child] <= num[child + 1]))
			child++;
		if (temp >= num[child])
			break;
		else {
			num[child / 2] = num[child];
			child *= 2;
		}
	}
	num[child / 2] = temp;
}

void heapsort(int num[], int n) {
	int i, temp;
	for (i = n / 2; i > 0; i--)
		makeheap(num, i, n);
	for (i = n - 1; i > 0; i--) {
		temp = num[1];
		num[1] = num[i + 1];
		num[i + 1] = temp;
		makeheap(num, 1, i);
	}
}

int main(void) {
	int i, n, min = 0;
	scanf("%d", &n);
	int *p;
	p = (int*)malloc(sizeof(int)*(n + 1));
	p[0] = 0;
	for (i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	heapsort(p, n);
	for (i = 1; i <= n; i++)
		printf("%d ", p[i]);
	for (i = 1; i <= n; i++) {
		p[i] += p[i - 1];
		min += p[i];
	}
	printf("%d", min);
	return 0;
}