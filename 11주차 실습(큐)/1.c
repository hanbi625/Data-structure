#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct que {
	int* q;
	int f, r, N;
}Que;
void init(Que*, int);
int isEmpty(Que*);
int isFull(Que*);
void enqueue(Que*, int);
int dequeue(Que*);
void print(Que*, int);
int main() {
	Que Q;
	int q, n, num;
	char ch;

	scanf("%d %d", &q, &n);

	init(&Q, q);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'I') {
			if (isFull(&Q)) {
				printf("overflow");
				print(&Q, Q.N);
			}
			else {
				scanf("%d", &num);
				enqueue(&Q, num);
			}
		}
		else if (ch == 'D') {
			if (isEmpty(&Q))
				printf("underflow\n");
			else
				dequeue(&Q);
		}
		else if (ch == 'P')
			print(&Q, q);
	}

	return 0;
}
void init(Que* Q, int N) {
	Q->q = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		Q->q[i] = 0;
	Q->f = 1;
	Q->r = 0;
	Q->N = N;
}
int isEmpty(Que* Q) {
	return (Q->r + 1) % Q->N == Q->f;
}
int isFull(Que* Q) {
	return (Q->r + 2) % Q->N == Q->f;
}
void enqueue(Que* Q, int n) {
	Q->r = (Q->r + 1) % Q->N;
	Q->q[Q->r] = n;
}
int dequeue(Que* Q) {
	int e = Q->q[Q->f];
	Q->q[Q->f] = 0;
	Q->f = (Q->f + 1) % Q->N;
	return e;
}
void print(Que* Q, int N) {
	for (int i = 0; i < N; i++)
		printf(" %d", Q->q[i]);
	printf("\n");
}
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct que {
	int* st;
	int f, r, N, cnt;
}QUE;
void init(QUE*, int);
void enqueue(QUE*, int);
void dequeue(QUE*);
void print(QUE*);
int isEmpty(QUE*);
int isFull(QUE*);
int main() {
	QUE que;
	int q, n, i, x;
	char ch;

	scanf("%d %d", &q, &n);
	init(&que, q);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'I') {
			scanf("%d", &x);
			if (isFull(&que)) {
				printf("overflow");
				print(&que);
				break;
			}
			enqueue(&que, x);
		}
		if (ch == 'D') {
			if (isEmpty(&que)) {
				printf("underflow");
				break;
			}
			dequeue(&que);
		}
		if (ch == 'P')
			print(&que);
	}

	return 0;
}
void init(QUE* q, int n) {
	q->st = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		q->st[i] = 0;
	q->f = 0; q->r = 0;
	q->N = n; q->cnt = 0;
}
void enqueue(QUE* q, int n) {
	q->r = (q->r + 1) % q->N;
	q->st[q->r] = n;
	q->cnt++;
}
void dequeue(QUE* q) {
	q->f = (q->f + 1) % q->N;
	q->st[q->f] = 0;
	q->cnt--;
}
void print(QUE* q) {
	int i = 0;
	for (i = 0; i < q->N; i++)
		printf(" %d", q->st[i]);

	printf("\n");
}
int isEmpty(QUE* q) {
	return q->cnt == 0;
}
int isFull(QUE* q) {
	return q->cnt == q->N - 1;
}
*/
