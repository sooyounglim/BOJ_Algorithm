#include "stdafx.h"
#include <iostream>
using namespace std;

int n;
int* height;
int* cross_left;	// 2*n-1
int *cross_right;	// 2*n-1
int result = 0;

void dfs(int depth) {
	if (depth >= n)	
		result++;
	for (int i = 0; i < n; i++) {
		if (height[i] || cross_left[depth + i] || cross_right[n - 1 + (depth - i)])
			continue;
		height[i] = 1;
		cross_left[depth + i] = 1;
		cross_right[n - 1 + (depth - i)] = 1;
		dfs(depth + 1);
		height[i] = 0;
		cross_left[depth + i] = 0;
		cross_right[n - 1 + (depth - i)] = 0;	// back-tracking
	}
}

int main(void) {
	cin >> n;
	height = (int*)malloc(sizeof(int)*n);
	cross_left = (int*)malloc(sizeof(int)*(2*n-1));
	cross_right = (int*)malloc(sizeof(int)*(2*n-1));
	dfs(0);
	cout << result << endl;
	delete[] height;
	delete[] cross_left;
	delete[] cross_right;
	return 0;
}	