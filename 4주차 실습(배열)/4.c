#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, M;
	int x[100][100] = { 0 };

	scanf("%d %d", &N, &M);

	int num = 1, val = 1;
	int row = M, col = N;
	int ir = 0, ic = -1;
	while (num <= N * M) {
		for (int i = 0; i < row; i++) {
			ic += val;
			x[ir][ic] = num++;
		}
		col--;
		for (int i = 0; i < col; i++) {
			ir += val;
			x[ir][ic] = num++;
		}
		row--;
		val *= -1;
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
	int row = 0, col = -1;
	int cnt = 0;
	int n = 1;
	while (num <= N * M) {
		for (i = 0; i < M - cnt; i++) {
			col += n;
			p[row][col] = num++;
		}
		for (i = 0; i < N - cnt - 1; i++) {
			row += n;
			p[row][col] = num++;
		}
		cnt++;
		n *= -1;
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
