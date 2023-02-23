#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* prefixAverages1(int* x, int n);
int* prefixAverages2(int* x, int n);
int main() {
	int* x = NULL;
	int* A;
	int N;

	scanf("%d", &N);
	x = (int*)malloc(N * sizeof(int));
	if (x == NULL) return -1;

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);
	A = prefixAverages1(x, N);
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
	A = prefixAverages2(x, N);
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);


	return 0;
}
int* prefixAverages1(int* x, int n) {
	int* A = NULL;
	double sum = 0;
	A = (int*)malloc(n * sizeof(int));
	if (A == NULL) return -1;

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++)
			sum += x[j];
		A[i] = (int)(sum / (i + 1) + 0.5);
	}
	return A;
}
int* prefixAverages2(int* x, int n) {
	int* A = NULL;
	double sum = 0;
	A = (int*)malloc(n * sizeof(int));
	if (A == NULL) return -1;

	for (int i = 0; i < n; i++) {
		sum += x[i];
		A[i] = (int)(sum / (i + 1) + 0.5);
	}
	return A;
}
