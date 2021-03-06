#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100002];
int n, v[100002], parent[100002];

void bfs(int node) {
	v[node] = 1;
	for (int i : tree[node]) {
		if (!v[i]) {
			parent[i] = node;
			bfs(i);
		}
	}
}

int main(void) {
	int i, from, to;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> from >> to;	// position
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	bfs(1);
	for (i = 2; i <= n; i++)
		cout << parent[i] << "\n";
	return 0;
}