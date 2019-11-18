#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int time = 0;

void hannoi(int n, char A, char B, char C)
{
	if (n == 1) {
		time++;
		printf("<%d>  %d: %c->%c\n", time, n, A, C);
	}
	else {
		hannoi(n - 1, A, C, B);
		time++;
		printf("<%d>  %d: %c->%c\n", time,n, A, C);
		hannoi(n - 1, B, A, C);
	}
}

int main(void)
{
	int n;
	char A = 'A';
	char B = 'B';
	char C = 'C';

	printf(" ‰»Î≤„ ˝£∫");
	scanf("%d", &n);

	hannoi(n, A, B, C);

	return 0;
}