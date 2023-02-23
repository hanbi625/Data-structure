#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int x[100][100] = { 0 };
	int N, i, j, num = 1;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		if (i % 2 == 0)
			for (j = 0; j < N; j++)
				x[i][j] = num++;
		else
			for (j = N - 1; j >= 0; j--)
				x[i][j] = num++;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf(" %d", x[i][j]);
		printf("\n");
	}

	return 0;
}
/* 동적할당 이용
#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, i, j;
	int** p = NULL;

	scanf("%d", &N);
	p = (int**)malloc(N * sizeof(int*));
	if (p == NULL) return -1;
	for (i = 0; i < N; i++) {
		p[i] = (int*)malloc(N * sizeof(int));
		if (p[i] == NULL) return -1;
	}

	int num = 1;

	for (i = 0; i < N; i++) {
		if ((i + 1) % 2 == 1) {
			for (j = 0; j < N; j++) {
				p[i][j] = num;
				num++;
			}
		}
		else {
			for (j = N - 1; j >= 0; j--) {
				p[i][j] = num;
				num++;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf(" %d", p[i][j]);
		printf("\n");
	}

	if (p != NULL) {
		for (i = 0; i < N; i++)
			free(p[i]);
		free(p);
		p = NULL;
	}

	return 0;
}
*/
