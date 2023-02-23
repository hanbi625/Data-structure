#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int fchar(char*, char, int);
int main() {
	char str[101] = { 0 }, ch;
	scanf("%s", str);
	getchar();
	scanf("%c", &ch);
	printf("%d", fchar(str, ch, 0));

	return 0;
}
int fchar(char* x, char c, int n) {
	int cnt = 0;
	if (*(x + n) == '\0') return 0;
	else {
		if (*(x + n) == c) cnt++;
		return cnt + fchar(x, c, n + 1);
	}
}
