#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gcd2(int, int);
int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", gcd2(a, b));

	return 0;
}
int gcd2(int a, int b) {
	if (b <= 0) return a;
	if (a <= 0) return b;
	else {
		if (a >= b) return gcd2(b, a - b);
		else return gcd2(a, b - a);
	}
}
