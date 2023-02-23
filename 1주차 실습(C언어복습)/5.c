#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct st {
	int h, m, s;
};
int main() {
	struct st t1, t2;
	int hour, min, sec;
	scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

	if (t2.s >= t1.s) {
		sec = t2.s - t1.s;
		if (t2.m >= t1.m) {
			min = t2.m - t1.m;
			hour = t2.h - t1.h;
		}
		else {
			min = t2.m + 60 - t1.m;
			hour = t2.h - 1 - t1.h;
		}
	}
	else {
		sec = t2.s + 60 - t1.s;
		t2.m -= 1;
		if (t2.m >= t1.m) {
			min = t2.m - t1.m;
			hour = t2.h - t1.h;
		}
		else {
			min = t2.m + 60 - t1.m;
			hour = t2.h - 1 - t1.h;
		}
	}
	printf("%d %d %d", hour, min, sec);
	return 0;
}
