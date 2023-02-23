#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void rhanoi(int, char, char, char);
int main() {
	int N;
	scanf("%d", &N);
	rhanoi(N, 'A', 'B', 'C');
	return 0;
}
void rhanoi(int n, char from, char aux, char to) {
	if (n == 1)
		printf("%c %c\n", from, to);
	else {
		rhanoi(n - 1, from, to, aux);
		printf("%c %c\n", from, to);
		rhanoi(n - 1, aux, from, to);
	}
}
