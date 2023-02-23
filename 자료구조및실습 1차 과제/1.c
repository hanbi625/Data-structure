#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* movingAverages1(int*, int, int);
int* movingAverages2(int*, int, int);
int getAverage(int*, int, int, int);
int main() {
	int* x = NULL;
	int* A = NULL;
	int n, k;

	scanf("%d %d", &n, &k);

	x = (int*)malloc(n * sizeof(int));
	if (x == NULL) return -1;

	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	A = movingAverages1(x, n, k);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	A = movingAverages2(x, n, k);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);


	return 0;
}
int getAverage(int *x, int j, int n, int k) {
	double sum = 0;
	for (int i = j; i <= n; i++) 
		sum += x[i];
	sum /= k;
	return (int)(sum + 0.5);
}
int* movingAverages1(int* x, int n, int k) {
	int* A = NULL;
	int i;
	A = (int*)malloc(n * sizeof(int));
	if (A == NULL) return -1;

	i = 0;
	while (n) {
		if (i < k - 1) 
			A[i] = getAverage(x, 0, i, i + 1);
		else 
			A[i] = getAverage(x, i - k + 1, i, k);
		i++;
		n--;
	}

	return A;
}
int* movingAverages2(int* x, int n, int k) {
	int* A = NULL;
	int i, j;
	double sum = 0;
	A = (int*)malloc(n * sizeof(int));
	if (A == NULL) return -1;

	for (i = 0; i < n; i++) {
		if (i <= k - 1) {
			sum += x[i];
			A[i] = (int)((sum / (i + 1)) + 0.5);
		}
		else {
			sum = sum - x[i - k];
			sum += x[i];
			A[i] = (int)((sum / k) + 0.5);
		}
	}

	return A;
}
