#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;
int card[500001];

bool twosearch(int left, int right, int searchnum) {
	int mid = (left + right) / 2;
	bool result;
	if (left > right || right < 0)
		return false;
	else {
		if (card[mid] > searchnum)
			result = twosearch(left, mid - 1, searchnum);
		else if (card[mid] < searchnum)
			result = twosearch(mid + 1, right, searchnum);
		else
			return true;
	}
}

int main(void) {
	int i, N, M;
	int search[500001];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &card[i]);
	sort(card, card + N);

	scanf("%d", &M);
	for (i = 0; i < M; i++)
		scanf("%d", &search[i]);
	for (i = 0; i < M; i++) {
		int searchNum = search[i];
		int left = 0, right = N - 1;
		int mid = (left + right) / 2;
		if (twosearch(left, right, searchNum))
			printf("1 ");
		else
			printf("0 ");
	}
	//while (M--) {
		//int num;
		//scanf("%d", &num);
		//printf("%d ", binary_search(card, card + N, num));
	//}
	return 0;
}