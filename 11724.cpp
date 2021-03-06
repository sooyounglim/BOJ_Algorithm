#include "stdafx.h"
#include <iostream>
using namespace std;

int n, m;
int graph[1001][1001];
int visited[1001];

void dfs(int start) {
	visited[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (graph[start][i] && !visited[i])
			dfs(i);
	}
}

int main(void) {
	int i;
	cin >> n >> m;	// 정점, 간선
	for (i = 0; i < m; i++) {
		int u, v;	// 간선의 양 끝점
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}	