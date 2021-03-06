#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n, d[200001], ans;
string str;

int main(void) {
	int i;
	cin >> n;
	cin >> str;
	stack<int> s;
	for (i = 0; str[i]; i++) {
		if (str[i] == '(')
			s.push(i);
		else {
			if (!s.empty()) {
				d[i] = d[s.top()] = 1;
				s.pop();
			}
		}
	}
	int val = 0;
	for (i = 0; str[i]; i++) {
		if (d[i]) {
			val++;
			if (ans < val)
				ans = val;
		}
		else 
			val = 0;
	}
	cout << ans;
	return 0;
}