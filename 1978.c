#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Prime(int x) {  // return 1: �Ҽ�
	int i;
	if (x == 1)
		return 0;
	else if (x == 2)
		return 1;
	else {
		for (i = 2; i < x; i++) {
			if (x%i == 0)
				return 0;
		}
		return 1;   // 2�̻� x �̸��� ���� ������ �������� ����.
	}
}

int main(void) {
	int N, cnt = 0;
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		if (Prime(x))
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}