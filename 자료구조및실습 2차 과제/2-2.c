#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void rIsPalindrome(char*, int, int);
int main() {
	char str[101] = { 0 };

	gets(str);
	rIsPalindrome(str, 0, strlen(str) - 1);

	return 0;
}
void rIsPalindrome(char* str, int st, int fin) {
	if (st >= fin) {
		printf("True\n");
		return;
	}
	else {
		if (str[st] != str[fin]) {
			printf("False\n");
			return;
		}
		rIsPalindrome(str, st + 1, fin - 1);
	}
}
