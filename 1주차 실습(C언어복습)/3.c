#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int*, int*);
int main() {
	int x[50] = { 0 };
	int N, a, b;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);
	scanf("%d %d", &a, &b);
	swap(x + a, x + b);

	for (int i = 0; i < N; i++)
		printf(" %d", x[i]);
	return 0;
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
