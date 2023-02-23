#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char str[101] = { 0 };
	int len = 0;

	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		printf("%s\n", str);
		char fir = str[0];
		for (int j = 1; j < len; j++)
			str[j - 1] = str[j];
		str[len - 1] = fir;
	}
	/*
	for (i = 0; i < len; i++) {
		printf("%s\n", x);
		for (j = 0; j < len - 1; j++) {
			char tmp = x[j];
			x[j] = x[j + 1];
			x[j + 1] = tmp;
		}
	}
	*/

	return 0;
}
