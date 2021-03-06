#include "stdafx.h"
#include <iostream>
using namespace std;

int main(void) {
	bool isPrime[1000001];
	int i, j, m, n;
	cin >> m >> n;
	for (i = 2; i <= n; i++)
		isPrime[i] = true;
	for (i = 2; i*i <= n; i++) {
		int t = 2;
		if (isPrime[i]) {	
			for (j = i * t; j <= n; j = i * t) {
				isPrime[j] = false;
				t++;
			}
		}
	}
	for (i = m; i <= n; i++) {
		if (isPrime[i])
			cout << i << endl;
	}
	return 0;
}