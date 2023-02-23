#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack {
	int* storage;
	int top;
}STACK;
void init(STACK*);
int pop(STACK*);
void push(STACK*, STACK*, int);
void print(STACK*);
int findMin(STACK*);
int main() {
	STACK stack;
	STACK minstack;
	int n, data, top;
	char ch;

	init(&stack);
	init(&minstack);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &ch);
		switch (ch) {
		case 'p':
			scanf("%d", &data);
			push(&stack, &minstack, data);
			print(&stack);
			break;
		case 'o':
			top = pop(&stack);
			if (minstack.storage[minstack.top] == top)
				pop(&minstack);
			print(&stack);
			break;
		case 'f':
			printf("%d\n", findMin(&minstack));
			break;
		case 'q':
			break;
		}
	}
	return 0;
}
void init(STACK* p) {
	p->top = -1;
	p->storage = (int*)malloc(sizeof(int) * 100);
}
int pop(STACK* p) {
	int e;
	if (p->top == -1)
		return;
	e = p->storage[p->top];
	p->top--;
	return e;
}
void push(STACK* p, STACK* m, int e) {
	if (p->top == 100)
		return;
	else {
		p->top++;
		p->storage[p->top] = e;
	}

	if (m->top == -1) {
		m->top++;
		m->storage[m->top] = e;
	}
	else {
		if (m->storage[m->top] >= e) {
			m->top++;
			m->storage[m->top] = e;
		}
	}
}
void print(STACK* p) {
	int i;
	for (i = p->top; i >= 0; i--)
		printf("%d ", p->storage[i]);
	printf("\n");
}
int findMin(STACK* p) {
	return p->storage[p->top];
}
