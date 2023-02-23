#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gcd(int, int);
int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));

	return 0;
}
int gcd(int a, int b) {
	if (a == 0) return b;
	else if (b == 0) return a;
	else {
		if (a >= b) gcd(b, a % b);
		else gcd(a, b % a);
	}
}
/*함수2
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
*/
