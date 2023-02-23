c#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int modulo(int, int);
int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));

	return 0;
}
int modulo(int a, int b) {
	if (a >= 0 && b > 0) {
		while (a >= b)
			a -= b;
	}
	return a;
}
/*
int modulo(int a, int b) {
	int result;
	if (a == 0 || b == 0)
		result = 0;
	else
		result = a;
	while (result >= b) {
		result = result - b;
	}
	return result;
}
*/
/*
int modulo(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	else {
		while (a >= b) {
			a -= b;
		}
	}
	return a;
}
*/
