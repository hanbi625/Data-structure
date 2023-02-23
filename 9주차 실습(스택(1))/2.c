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
void print(STACK*);
int isEmpty(STACK*);
void isBalanced(char*);
int isOpenSymbol(char);
int isCloseSymbol(char);
int isCounterpart(char, char);
int main() {
	char st[1001] = { 0 };
	int len = 0;

	gets(st);
	isBalanced(st);

	return 0;
}
void isBalanced(char* str) {
	STACK S;
	char s, t;
	int i = 0, cnt = 0;
	init(&S, strlen(str));
	for (int i = 0; i < strlen(str); i++) {
		if (isOpenSymbol(str[i]) || isCloseSymbol(str[i]))
			cnt++;
	}
	while (str[i] != '\0') {
		s = str[i];
		if (isOpenSymbol(s))
			push(&S, s);
		else if (isCloseSymbol(s)) {
			if (isEmpty(&S)) {
				printf("Wrong_%d", cnt);
				return;
			}
			t = pop(&S);
			if (!(isCounterpart(s, t))) {
				printf("Wrong_%d", cnt);
				return;
			}
		}
		i++;
	}
	if (isEmpty(&S))
		printf("OK_%d", cnt);
	else
		printf("Wrong_%d", cnt);
}
int isOpenSymbol(char s) {
	if (s == '(' || s == '[' || s == '{')
		return 1;
	else return 0;
}
int isCloseSymbol(char s) {
	if (s == ')' || s == ']' || s == '}')
		return 1;
	else return 0;
}
int isCounterpart(char s, char t) {
	if (t == '(' && s == ')')
		return 1;
	else if (t == '[' && s == ']')
		return 1;
	else if (t == '{' && s == '}')
		return 1;
	else return 0;
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
void print(STACK* p) {
	for (int i = p->top; i >= 0; i--)
		printf("%c", p->st[i]);
	printf("\n");
}
int isEmpty(STACK* p) {
	return p->top == -1;
}

/*
#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void isBalanced(char str[1001]);
void push(char stack[1001], int *t, char ch);
char pop(char stack[1001], int *t, char ch);
char counterpart(char ch, char res, int *t);
int main() {
	char str[1000] = "";

	gets(str);
	isBalanced(str);

	return 0;
}
void isBalanced(char str[1001]) {
	int N, i, len = 0, t = 0, cnt = 0, flag = 0;
	char ch = '\0', stack[1001] = "", res = '\0', tf = '\0';

	len = strlen(str);

	for (i = 0; i < len; i++)
		if (str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == ')' || str[i] == '}' || str[i] == ']')
			cnt++;

	for (i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			push(stack, &t, str[i]);
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (t == 0) {
				printf("Wrong_%d", cnt);
				flag++;
				break;
			}
			else {
				res = pop(stack, &t, str[i]);
				tf = counterpart(str[i], res, &t);
				if (tf == 'F') {
					printf("Wrong_%d", cnt);
					flag++;
					break;
				}
			}
		}
	}
	if (flag == 0) {
		if(t==0)
			printf("OK_%d", cnt);
		else
			printf("Wrong_%d", cnt);
	}
}
void push(char stack[1001], int *t, char ch) {
	stack[*t] = ch;
	(*t)++;
}
char pop(char stack[1001], int *t, char ch) {
	if (*t == 0) {
		printf("Stack Empty\n");
		return;
	}
	(*t)--;
	return stack[*t];
}
char counterpart(char ch, char res, int *t) {
	if (ch == ')') {
		if (res != '(')
			return 'F';
		else
			return 'T';
	}
	if (ch == '}') {
		if (res != '{')
			return 'F';
		else
			return 'T';
	}
	if (ch == ']') {
		if (res != '[')
			return 'F';
		else
			return 'T';
	}
}
*/
