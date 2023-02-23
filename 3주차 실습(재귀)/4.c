#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int rmax(int*, int);
int main() {
	int* x = NULL;
	int N;

	scanf("%d", &N);
	x = (int*)malloc(N * sizeof(int));
	if (x == NULL) return -1;

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);
	printf("%d", rmax(x, N));

	return 0;
}
int rmax(int* x, int n) {
	int max;
	if (n == 0) return x[0];
	max = rmax(x, n - 1);
	if (max < x[n - 1]) max = x[n - 1];
	return max;
}
