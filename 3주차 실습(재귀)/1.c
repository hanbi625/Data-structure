#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sum(int N);
int main() {
	int N;

	scanf("%d", &N);
	printf("%d", sum(N));

	return 0;
}
int sum(int N) {
	if (N == 1) return 1;
	else return N + sum(N - 1);
}
