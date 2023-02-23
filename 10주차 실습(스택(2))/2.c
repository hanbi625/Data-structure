#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int n;
	struct node* next;
}NODE;
typedef struct stack {
	NODE* top;
}STACK;
void init(STACK*);
void push(STACK*, int);
int pop(STACK*);
int isEmpty(STACK*);
int top(STACK*);
void evaluate(char*);
int toNum(char);
int doOperator(char, int, int);
int isOperand(char);
int main() {
	STACK stack;
	int N;
	char str[101] = { 0 };

	init(&stack);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", str);
		evaluate(str);
	}

	return 0;
}
void evaluate(char* str) {
	STACK S;
	int i = 0, a, b;
	init(&S);
	while (i < strlen(str)) {
		if (isOperand(str[i]))
			push(&S, toNum(str[i]));
		else {
			a = pop(&S);
			b = pop(&S);
			push(&S, doOperator(str[i], b, a));
		}
		i++;
	}
	printf("%d\n", pop(&S));
}
int isOperand(char ch) {
	if (ch >= '0' && ch <= '9') return 1;
	return 0;
}
int doOperator(char op, int x, int y) {
	int v = 0;
	switch (op) {
	case '+': v = x + y; break;
	case '-': v = x - y; break;
	case '*': v = x * y; break;
	case '/': v = x / y; break;
	}
	return v;
}
int toNum(char ch) {
	return ch - '0';
}
void init(STACK* s) {
	s->top = NULL;
}
void push(STACK* s, int n) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->n = n;
	node->next = s->top;
	s->top = node;
}
int pop(STACK* s) {
	if (isEmpty(s))
		return -1;
	int e = s->top->n;
	NODE* p = s->top;
	s->top = s->top->next;
	free(p); p = NULL;
	return e;
}
int isEmpty(STACK* s) {
	return s->top == NULL;
}
int top(STACK* s) {
	return s->top->n;
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack {
	int *x;
	int top;
}STACK;
void init(STACK* st);
void evaluate(char* ch);
char pop(STACK*);
char peek(STACK*);
void push(STACK*, int);
int num(char ch);
int order(char ch);
int doOperator(char, int, int);
int main()
{
	char ch[101] = { 0 };
	int N, len = 0;

	scanf("%d", &N); //수식의 개수 입력받기

	for (int i = 0; i < N; i++) { //N개의 수식 입력받기
		getchar();
		scanf("%s", ch);
		evaluate(ch);
		printf("\n");
	}

}
void init(STACK* st) {
	st->top = -1;
}
char pop(STACK* p) {
	char ch;
	if (p->top == -1)
		return;
	ch = p->x[p->top];
	p->top--;
	return ch;
}
void push(STACK* p, int n) {
	if (p->top == 100)
		return;
	p->top++;
	p->x[p->top] = n;
}
char peek(STACK* p) {
	if (p->top == -1)
		return;
	return p->x[p->top];
}
int num(char ch) {
	return ch - '0';
}
void evaluate(char* ch) {
	STACK st;
	int i = 0, a, b;
	init(&st);
	st.x = (int*)malloc(sizeof(int) * (strlen(ch) + 1));
	while (i < strlen(ch)) {
		if (ch[i] >= '0' && ch[i] <= '9') 
			push(&st, num(ch[i]));
		else {
			a = pop(&st);
			b = pop(&st);
			push(&st, doOperator(ch[i], b, a));
		}
		i++;
	}
	printf("%d", pop(&st));
}
int doOperator(char ch, int x, int y) {
	int v;
	switch (ch) {
	case '+' :
		v = x + y;
		break;
	case '-' :
		v = x - y;
		break;
	case '*' :
		v = x * y;
		break;
	case '/' :
		v = x / y;
	}
	return v;
}
*/
