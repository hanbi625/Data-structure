#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct st {
	char name[10];
	int s;
};
int main() {
	struct st st[5];
	double sum = 0, avg;

	for (int i = 0; i < 5; i++) {
		scanf("%s %d", st[i].name, &st[i].s);
		getchar();
		sum += st[i].s;
	}
	avg = sum / 5;
	for (int i = 0; i < 5; i++)
		if (st[i].s <= avg)
			printf("%s\n", st[i].name);

	return 0;
}
