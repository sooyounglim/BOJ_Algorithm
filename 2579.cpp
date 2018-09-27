#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int i, n, sum = 0;
	cin >> n;
	int* stair = new int[n+1];
	int* dp = new int[n + 1];
	stair[0] = dp[0] = 0;
	for (i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1] = stair[1];
	dp[2] = max(stair[1], stair[1] + stair[2]);
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	for (i = 4; i <= n; i++)
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	cout << dp[n];

	delete[] stair;
	delete[] dp;
	return 0;
}