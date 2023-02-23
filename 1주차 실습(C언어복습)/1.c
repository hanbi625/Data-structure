#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sum(int);
int main() {
	int x, s = 0;

	scanf("%d", &x);
	for (int i = 1; i <= x; i++)
		s += sum(i);
	printf("%d", s);

	return 0;
}
int sum(int n) {
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;
}
