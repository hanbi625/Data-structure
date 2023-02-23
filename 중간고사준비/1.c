#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Power(int, int);
int main() {
	int x, n;

	scanf("%d %d", &x, &n);
	printf("%d", Power(x, n));
	
	return 0;
}
int Power(int x, int n) {
	if (n == 0) return 1;
	else return x * Power(x, n - 1);
}
