#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int* p = NULL;
	int* q = NULL;
	int N, i, j;

	scanf("%d", &N);
	p = (int*)malloc(N * sizeof(int));
	if (p == NULL) return -1;
	q = (int*)malloc(N * sizeof(int));
	if (q == NULL) return -1;

	for (i = 0; i < N; i++)
		scanf("%d", &p[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &q[i]);
	for (i = 0, j = N - 1; i < N; i++, j--)
		printf(" %d", p[i] + q[j]);

	if (p != NULL) {
		free(p); p = NULL;
	}
	if (q != NULL) {
		free(q); q = NULL;
	}

	return 0;
}
