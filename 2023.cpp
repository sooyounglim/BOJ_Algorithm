#include "stdafx.h"
#include <iostream>

using namespace std;

bool isPrime(int num) {
	int i;
	if (num < 2)	return false;
	for (i = 2; i*i <= num; i++)
		if (num%i == 0)	return false;
	return true;
}

void dfs(int num, int n) {
	int i;
	if (n == 0)
		cout << num << endl;
	for (i = 1; i < 10; i += 2) {
		int prime = num * 10 + i;
		if (isPrime(prime))
			dfs(prime, n - 1);
	}
}

int main(void) {
	int i, n;
	int prime[4] = { 2, 3, 5, 7 };
	cin >> n;
	for (i = 0; i < 4; i++)
		dfs(prime[i], n - 1);
	return 0;
}