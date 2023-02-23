#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void change(int*, int, int);
int main() {
	int N, i, num, idx, sidx;
	int* x = NULL;

	scanf("%d", &N);

	x = (int*)malloc(N * sizeof(int));
	if (x == NULL) return -1;

	for (i = 0; i < N; i++)
		scanf("%d", &x[i]);
	scanf("%d", &num);
	scanf("%d", &idx);
	for (i = 0; i < num - 1; i++) {
		scanf("%d", &sidx);
		change(x, idx, sidx);
	}
	for (i = 0; i < N; i++)
		printf(" %d", x[i]);

	if (x != NULL) {
		free(x);
		x = NULL;
	}

	return 0;
}
void change(int *x, int idx, int sidx) {
	int tmp = x[idx];
	x[idx] = x[sidx];
	x[sidx] = tmp;
}
