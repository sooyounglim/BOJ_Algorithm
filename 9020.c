#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime[10001] = { 0 };

void FindPrime() {
	int i, j;
	for (i = 2; i*i < 10001; i++) {
		if (!prime[i]) {
			for (j = i * i; j < 10001; j += i)
				prime[j] = 1;
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	FindPrime();
	while (T--) {
		int i, n, n1, n2;
		scanf("%d", &n);
		for (i = 0; i <= n / 2; i++) {
			if (n < i)	break;
			if (!prime[i] && !prime[n-i]) {
				n1 = i;
				n2 = n - i;
			}	
		}
		printf("%d %d\n", n1, n2);
	}
	return 0;
}