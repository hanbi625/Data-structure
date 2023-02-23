#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack {
	int* st;
	int top;
}STACK;
typedef struct que {
	STACK *st1;
	STACK *st2;
}Que;
void initque(Que*);
STACK* initstack();
void push(STACK*, int);
void enqueue(Que*, int);
void move(Que*);
void dequeue(Que*);
void front(Que*);
int pop(STACK*);
int isEmpty(STACK*);
int main() {
	Que que;
	char ch;
	int n, elem;

	initque(&que);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'I') {
			scanf("%d", &elem);
			enqueue(&que, elem);
		}
		if (ch == 'D')
			dequeue(&que);
		if (ch == 'F')
			front(&que);
	}

	return 0;
}
void initque(Que* q) {
	q->st1 = initstack();
	q->st2 = initstack();
}
STACK* initstack() {
	STACK* s = (STACK*)malloc(sizeof(STACK));
	s->st = (int*)malloc(sizeof(int) * 100);
	s->top = -1;
	return s;
}
void push(STACK* s, int x) {
	s->top++;
	s->st[s->top] = x;
}
void enqueue(Que* q, int x) {
	push(q->st1, x);
}
void move(Que* q) {
	while (!isEmpty(q->st1))
		push(q->st2, pop(q->st1));
}
int pop(STACK* s) {
	int e = s->st[s->top];
	s->top--;
	return e;
}
void dequeue(Que* q) {
	if (isEmpty(q->st2))
		move(q);
	if (isEmpty(q->st2))
		return;
	int e = pop(q->st2);
	printf("%d\n", e);
}
void front(Que* q) {
	if (isEmpty(q->st2))
		move(q);
	printf("%d\n", q->st2->st[q->st2->top]);
}
int isEmpty(STACK* s) {
	return s->top == -1;
}
