#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct deque {
	int *D;
	int r, f;
	int N;
}DEQ;
void init(DEQ *, int);
void add_front(DEQ *, int);
void add_rear(DEQ *, int);
int delete_front(DEQ *);
int delete_rear(DEQ *);
void print(DEQ *);
int isEmpty(DEQ *);
int isFull(DEQ *);
int main() {
	DEQ deq;
	int N, x;
	char st[5] = { 0 };
	scanf("%d", &N);
	init(&deq, N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", st);
		if (strcmp(st, "AF") == 0) {
			if (isFull(&deq)) {
				printf("overflow\n");
				break;
			}
			scanf("%d", &x);
			add_front(&deq, x);
		}
		else if (strcmp(st, "AR") == 0) {
			if (isFull(&deq)) {
				printf("overflow\n");
				break;
			}
			scanf("%d", &x);
			add_rear(&deq, x);
		}
		else if (strcmp(st, "DF") == 0) {
			if (isEmpty(&deq)) {
				printf("underflow\n");
				break;
			}
			delete_front(&deq);
		}
		else if (strcmp(st, "DR") == 0) {
			if (isEmpty(&deq)) {
				printf("underflow\n");
				break;
			}
			delete_rear(&deq);
		}
		else if (strcmp(st, "P") == 0)
			print(&deq);
	}
	return 0;
}
int isEmpty(DEQ *d) {
	return d->r == d->f;
}
int isFull(DEQ *d) {
	return ((d->r + 1) % d->N) == d->f;
}
void init(DEQ *deq, int N) {
	deq->D = NULL;
	deq->D = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		deq->D[i] = 0;
	deq->f = deq->r = 0;
	deq->N = N - 1;
}
void add_front(DEQ *d, int x) {
	d->D[d->f] = x;
	d->f = (d->f - 1 + d->N) % d->N;
}
void add_rear(DEQ *d, int x) {
	d->r = (d->r + 1) % d->N;
	d->D[d->r] = x;
}
int delete_front(DEQ *d) {
	int e = d->D[d->f];
	d->f = (d->f + 1) % d->N;
	return e;
}
int delete_rear(DEQ *d) {
	int e = d->D[d->r];
	d->r = (d->r - 1 + d->N) % d->N;
	return e;
}
void print(DEQ *d) {
	int i, f, r;
	if (isEmpty(d)) {
		printf("underflow\n");
		return;
	}
	f = d->f;
	r = d->r;
	i = (f + 1) % d->N;
	while (i != r) {
		printf(" %d", d->D[i]);
		i = (i + 1) % d->N;
	}
	printf(" %d\n", d->D[i]);
}
