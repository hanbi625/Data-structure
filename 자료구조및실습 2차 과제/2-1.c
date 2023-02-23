#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void isPalindrome(char*, int);
int main() {
	char A[101] = { 0 };
	int n;

	gets(A);
	n = strlen(A);
	isPalindrome(A, n);
	
	return 0;
}
void isPalindrome(char* A, int n) {
	int tmp = 0;
	for (int i = 0; i < n / 2; i++) {
		if (A[i] != A[n - i - 1]) {
			printf("False\n");
			tmp = 1;
			break;
		}
	}
	if (tmp == 0) printf("True\n");
}
