#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void change(int*, int, int);
int main() {
	int N, a, b, num;
	int* x = NULL;

	scanf("%d", &N);
	x = (int*)malloc(N * sizeof(int));
	if (x == NULL) return -1;

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &a, &b);
		change(x, a, b);
	}
	for (int i = 0; i < N; i++)
		printf(" %d", x[i]);

	if (x != NULL) {
		free(x);
		x = NULL;
	}
	return 0;
}
void change(int* x, int a, int b) {
	if (b - a == 1) {
		int tmp = x[a];
		x[a] = x[b];
		x[b] = tmp;
	}
	else {
		for (int i = 0; i <= (b - a) / 2; i++) {
			int tmp = x[a + i];
			x[a + i] = x[b - i];
			x[b - i] = tmp;
		}
	}
}
/*함수2
void change(int* x, int a, int b) {

	for (int i = 0; a + i <= b - i; i++) {
		int tmp = x[a + i];
		x[a + i] = x[b - i];
		x[b - i] = tmp;
	}

}
*/
/*함수3
void change(int* x, int a, int b) {
	int size;
	int i;

	if (b == a)	size = 0;
	else if (b == a + 1) size = 1;
	else
		size = (b - a + 1) / 2;

	for (i = 0; i < size; i++) {
		int tmp = x[a];
		x[a] = x[b];
		x[b] = tmp;
		a++, b--;
	}
}*/
