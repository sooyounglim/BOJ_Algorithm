#include "stdafx.h"
#include <cstdio>

int main() {
	int a[200001], v[200001];
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for (int i = m; i >= 1; i--) {
		if (!v[a[i]]) {
			printf("%d\n", a[i]);
			v[a[i]] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i])
			printf("%d\n", i);
	}
	return 0;
}