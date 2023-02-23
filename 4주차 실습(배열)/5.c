#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, M;
	int x[100][100] = { 0 };

	scanf("%d %d", &N, &M);

	int num = 1, i, j, k;

	for (k = 0; k < N + M; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (i + j == k)
					x[i][j] = num++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", x[i][j]);
		}
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
	int N, M, i, j;
	int** p = NULL;

	scanf("%d %d", &N, &M);

	p = (int**)malloc(N * sizeof(int*));
	if (p == NULL) return -1;
	for (i = 0; i < N; i++) {
		p[i] = (int*)malloc(M * sizeof(int));
		if (p[i] == NULL) return -1;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			p[i][j] = 0;
	}
	int num = 1;
	for (i = 0; i < N + M - 1; i++) {
		for (j = 0; j < N; j++) {
			for (int k = 0; k < M; k++)
				if (j + k == i) {
					p[j][k] = num++;
					break;
				}
		}
	}


	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
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
