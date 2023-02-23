#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack {
	char* st;
	int size;
	int top;
}STACK;
void init(STACK*, int);
void push(STACK*, char);
char pop(STACK*);
void peek(STACK*);
void duplicate(STACK*);
void upRotate(STACK*, int);
void downRotate(STACK*, int);
void print(STACK*);
int main() {
	STACK stack;
	char str[10] = { 0 }, ch;
	int N, num, n;
	scanf("%d", &N);
	init(&stack, N);
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		getchar();
		scanf("%s", str);
		if (strcmp(str, "POP") == 0)
			pop(&stack);
		else if (strcmp(str, "PUSH") == 0) {
			getchar();
			scanf("%c", &ch);
			push(&stack, ch);
		}
		else if (strcmp(str, "PEEK") == 0)
			peek(&stack);
		else if (strcmp(str, "DUP") == 0)
			duplicate(&stack);
		else if (strcmp(str, "UpR") == 0) {
			scanf("%d", &n);
			upRotate(&stack, n);
		}
		else if (strcmp(str, "DownR") == 0) {
			scanf("%d", &n);
			downRotate(&stack, n);
		}
		else if (strcmp(str, "PRINT") == 0)
			print(&stack);
	}
	return 0;
}
void init(STACK* p, int N) {
	p->st = (char*)malloc(sizeof(char) * N);
	p->top = -1;
	p->size = N - 1;
}
void push(STACK* p, char ch) {
	if (p->top >= p->size) {
		printf("Stack FULL\n");
		return;
	}
	p->top++;
	p->st[p->top] = ch;
}
char pop(STACK* p) {
	if (p->top <= -1) {
		printf("Stack Empty\n");
		return -1;
	}
	char e = p->st[p->top];
	p->top--;
	return e;
}
void peek(STACK* p) {
	if (p->top <= -1) {
		printf("Stack Empty\n");
		return;
	}
	printf("%c\n", p->st[p->top]);
}
void duplicate(STACK* p) {
	if (p->top >= p->size) {
		printf("Stack FULL\n");
		return;
	}
	char e = pop(p);
	push(p, e);
	push(p, e);
}
void upRotate(STACK* p, int n) {
	int t = p->top;
	if (n > (p->top) + 1)
		return;
	for (int i = 0; i < n - 1; i++) {
		char tmp = p->st[t - i];
		p->st[t - i] = p->st[t - i - 1];
		p->st[t - i - 1] = tmp;
	}
}
void downRotate(STACK* p, int n) {
	int t = p->top;
	if (n > (p->top) + 1)
		return;
	for (int i = n - 2; i >= 0; i--) {
		char tmp = p->st[t - i];
		p->st[t - i] = p->st[t - i - 1];
		p->st[t - i - 1] = tmp;
	}
}
/* upRotate 와 downRotate 함수 또 다른 구현 방식
void upRotate(STACK* p, int n) {
	char ch;
	int t;
	t = p->top;
	ch = p->storage[t];
	if (n - 1 <= p->top) {
		for (int i = 0; i < n - 1; i++) {
			p->storage[t] = p->storage[t - 1];
			t--;
		}
		p->storage[t] = ch;
	}
}
void downRotate(STACK* p, int n) {
	char ch;
	int t;
	t = p->top - n + 1;
	ch = p->storage[t];
	if (n - 1 <= p->top) {
		for (int i = 0; i < n - 1; i++) {
			p->storage[t] = p->storage[t + 1];
			t++;
		}
		p->storage[p->top] = ch;
	}
}
*/
void print(STACK* p) {
	for (int i = p->top; i >= 0; i--)
		printf("%c", p->st[i]);
	printf("\n");
}
