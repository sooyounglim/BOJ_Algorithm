#include "stdafx.h"
#include <iostream>
using namespace std;

int n;
int post_order[100001];
int pre_order[100001];
int in_order_idx[100001];
int pre_order_idx;

void change_to_preorder(int in_start, int in_end, int post_start, int post_end) {
	if (!(in_start <= in_end) || !(post_start <= post_end)) {
		return;
	}
	int root = post_order[post_end];
	pre_order[pre_order_idx++] = root;

	int root_index = in_order_idx[root];
	change_to_preorder(in_start, root_index - 1, post_start, post_start + root_index - in_start - 1);
	change_to_preorder(root_index + 1, in_end, post_start + root_index - in_start, post_end - 1);
}

int main() {
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		int inorder;
		cin >> inorder;
		in_order_idx[inorder] = i;
	}
	for (i = 0; i < n; i++)
		cin >> post_order[i];
	change_to_preorder(0, n - 1, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << pre_order[i] << ' ';
	return 0;
}