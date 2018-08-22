#include <stdio.h> 

int main(void) {
	int T, i, j;

	struct STACK {
		char arr[50];
		int bracket;
	};
	scanf("%d", &T);
	struct STACK s[10000];

	for (i = 0; i < T; i++) {
		s[i].bracket = 0;
		scanf("%s", s[i].arr); 
		for (j = 0; j < 50; j++) {
			if (s[i].arr[j] == '\0')
				break;
			if (s[i].arr[j] == '(')
				s[i].bracket++;
			else if (s[i].arr[j] == ')') {
				if (s[i].bracket > 0)
					s[i].bracket--;
				else {
					s[i].bracket--;
					break;
				}
			}
		}
	}
	for (i = 0; i < T; i++) {
		if (s[i].bracket == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}