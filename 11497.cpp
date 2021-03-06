#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int i, n, level = 0;
		cin >> n;
		int* arr = new int[n];
		int* wood = new int[n];
		for (i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		int front = 0, rear = n - 1;
		for (i = 0; i < n; i++) {
			if (i % 2) {
				wood[rear] = arr[i];
				rear--;
			}
			else {
				wood[front] = arr[i];
				front++;
			}
		}
		for (i = 1; i < n; i++) 
			level = max(level, abs(wood[i] - wood[i - 1]));
		cout << level << endl;
		delete[] arr;
		delete[] wood;
	}
	return 0;
}