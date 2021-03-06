#include "stdafx.h"
#include <iostream>

using namespace std;

int N;
int tree[26][2];	// 좌, 우: 자식노드

void preorder(int node) {
	if (node == (int)('.' - 'A'))
		return;
	cout << (char)(node + 'A');
	preorder(tree[node][0]);
	preorder(tree[node][1]);
};

void inorder(int node) {
	if (node == (int)('.' - 'A'))
		return;
	inorder(tree[node][0]);
	cout << (char)(node + 'A');
	inorder(tree[node][1]);
};

void postorder(int node) {
	if (node == (int)('.' - 'A'))
		return;
	postorder(tree[node][0]);
	postorder(tree[node][1]);
	cout << (char)(node + 'A');
};

int main() {
	cin >> N;
	char node, left, right;
	for (int i = 0; i < N; i++) {
		cin >> node >> left >> right;
		tree[node - 'A'][0] = left - 'A';
		tree[node - 'A'][1] = right - 'A';
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	return 0;
}