#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mostOnes(int**, int);
int main() {
	int** A = NULL;
	int n;

	scanf("%d", &n);
	A = (int**)malloc(n * sizeof(int*));
	if (A == NULL) return -1;
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(n * sizeof(int));
		if (A[i] == NULL) return -1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	printf("%d", mostOnes(A, n));

	return 0;
}
int mostOnes(int** A, int n) {
	int row, i, j;

	row = i = j = 0;
	while ((i < n) && (j < n)) {
		if (A[i][j] == 0)
			i++;
		else {
			row = i;
			j++;
		}
	}
	return row;
}
/* 함수2
int mostOnes(int** A, int n) {
	int i, j, row, jmax;
	row = jmax = 0;
	for (i = 0; i < n; i++) {
		j = 0;
		while ((j < n) && (A[i][j] == 1))
			j++;
		if (j > jmax) {
			row = i;
			jmax = j;
		}
	}
	return row;
}
*/
/*함수3
int mostOnes(int** A, int n) {
	int row, i, j;

	row = i = j = 0;
	while (1) {
		while (A[i][j] == 1) {
			j++;
			if (j == n) return i;
		}
		row = i;
		while (A[i][j] == 0) {
			i++;
			if (i == n) return row;
		}
	}

}
*/
/*함수4
int mostOnes(int **A, int n) {
	int i, j, maxi = 0, max;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		if (A[0][i] == 1)
			cnt++;
	}
	maxi = 0, max = cnt;

	for (i = 1; i < n; i++) {
		cnt = 0;
		for (j = 0; j < n; j++)
			if (A[i][j] == 1)
				cnt++;
		if (cnt > max) {
			max = cnt;
			maxi = i;
		}
	}
	return maxi;
}*/
