#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001];
int check[1001];
int n, m, v;

void dfs(int start) {
	check[start] = 1;
	cout << start << " ";
	for (int i = 1; i <= n; i++) {
		if (graph[start][i] && !check[i])
			dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	for (int i = 0; i <= n; i++)
		check[i] = 0;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		cout << c << " ";
		for (int i = 1; i <= n; i++) {
			if (graph[c][i] && !check[i]) {
				check[i] = 1;
				q.push(i);
			}
		}
	}
}

int main(void) {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);
    return 0;
}	

