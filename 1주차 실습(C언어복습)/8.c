#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct st {
	char name[8];
	int k, e, m;
	double avg;
} st;
int main() {
	st* x = NULL;
	int N;
	double sum = 0;
	
	scanf("%d", &N);
	x = (st*)malloc(N * sizeof(st));
	if (x == NULL) return -1;

	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", x[i].name, &x[i].k, &x[i].e, &x[i].m);
		getchar();
		sum = x[i].k + x[i].e + x[i].m;
		x[i].avg = sum / 3;
	}

	for (int i = 0; i < N; i++) {
		printf("%s %.1f ", x[i].name, x[i].avg);
		if (x[i].k >= 90 || x[i].m >= 90 || x[i].e >= 90)
			printf("GREAT ");
		if (x[i].k < 70 || x[i].e < 70 || x[i].m < 70)
			printf("BAD ");
		printf("\n");
	}

	return 0;
}
