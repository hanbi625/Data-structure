#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int* x = NULL, * y = NULL;
	int N;

	scanf("%d", &N);
	x = (int*)malloc(N * sizeof(int));
	if (x == NULL) return -1;
	y = (int*)malloc(N * sizeof(int));
	if (y == NULL) return -1;

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &y[i]);
	for (int i = 0; i < N; i++)
		printf(" %d", x[i] + y[N - 1 - i]);

	if (p != NULL) {
		free(p); p = NULL;
	}
	if (q != NULL) {
		free(q); q = NULL;
	}

	return 0;
}
