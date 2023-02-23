#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ABC(int*, int);
int main() {
	int x[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < 9; i++)
		ABC(x, i);
	for (int i = 0; i < 10; i++)
		printf(" %d", x[i]);

	return 0;
}
void ABC(int* x, int k) {
	int max, mi;

	max = x[k];
	mi = k;
	for (int i = k; i < 10; i++)
		if (max < x[i]) {
			max = x[i];
			mi = i;
		}
	

	int tmp = x[k];
	x[k] = x[mi];
	x[mi] = tmp;
}
