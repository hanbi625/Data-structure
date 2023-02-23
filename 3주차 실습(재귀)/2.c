#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void rdigit(int);
int main() {
	int N;

	scanf("%d", &N);
	rdigit(N);

	return 0;
}
void rdigit(int N) {
	if (N < 10) printf("%d\n", N);
	else {
		rdigit(N / 10);
		printf("%d\n", N % 10);
	}
}
