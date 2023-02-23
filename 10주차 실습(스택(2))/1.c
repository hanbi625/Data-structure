#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	char ch;
	struct node* next;
}NODE;
typedef struct stack {
	NODE* top;
}STACK;
void init(STACK*);
void push(STACK*, char);
char pop(STACK*);
void convert(char*);
int isOperand(char);
int isEmpty(STACK*);
int rank(char);
char top(STACK*);
int main() {
	STACK stack;
	int N;
	char str[101] = { 0 };

	init(&stack);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", str);
		convert(str);
	}

	return 0;
}
void init(STACK* s) {
	s->top = NULL;
}
void push(STACK* s, char ch) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->ch = ch;
	node->next = s->top;
	s->top = node;
}
char pop(STACK* s) {
	if (isEmpty(s))
		return -1;
	char e = s->top->ch;
	NODE* p = s->top;
	s->top = s->top->next;
	free(p);
	p = NULL;
	return e;
}
void convert(char* str) {
	STACK S;
	int i = 0, flag = 0;
	init(&S);
	while (i < strlen(str)) {
		if (isOperand(str[i])) {
			printf("%c", str[i]);
			flag = 1;
		}
		else if (str[i] == '(') {
			push(&S, str[i]);
			flag = 1;
		}
		else if (str[i] == ')') {
			while (top(&S) != '(')
				printf("%c", pop(&S));
			pop(&S);
			flag = 1;
		}
		else {
			if (flag == 0) {
				if (str[i] == '+')
					push(&S, 'p');
				else if (str[i] == '-')
					push(&S, 'm');
				else flag++;
			}
			if (flag != 0) {
				while (!isEmpty(&S) && (rank(str[i]) <= rank(top(&S)))) {
					if (top(&S) == 'p')
						S.top->ch = '+';
					else if (top(&S) == 'm')
						S.top->ch = '-';
					printf("%c", pop(&S));
				}
				push(&S, str[i]);
				if (str[i] == str[i + 1]) {
					push(&S, str[i]);
					i++;
				}
				flag = 0;
			}
		}
		i++;
	}
	while (!isEmpty(&S))
		printf("%c", pop(&S));
	printf("\n");
}
int isOperand(char s) {
	if (s >= 'A' && s <= 'Z')
		return 1;
	return 0;
}
int isEmpty(STACK* s) {
	return s->top == NULL;
}
int rank(char s) {
	switch (s) {
	case '!': case 'p': case 'm': return 6;
	case '*': case '/': return 5;
	case '+': case '-': return 4;
	case '>': case '<': return 3;
	case '&': return 2;
	case'|': return 1;
	default: return -1;
	}
}
char top(STACK* s) {
	return s->top->ch;
}
/* 또 다른 방법
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack {
	char* x;
	int top;
}STACK;
void init(STACK* st);
void convert(char* ch);
char pop(STACK*);
char peek(STACK*);
void push(STACK*, char);
int order(char ch);
int isOperand(char ch);
int main()
{
	char ch[101] = { 0 };
	int N, len = 0;

	scanf("%d", &N); //수식의 개수 입력받기

	for (int i = 0; i < N; i++) { //N개의 수식 입력받기
		getchar();
		scanf("%s", ch);
		convert(ch);
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
void push(STACK* p, char ch) {
	if (p->top == 100)
		return;
	p->top++;
	p->x[p->top] = ch;
}
char peek(STACK* p) {
	if (p->top == -1)
		return;
	return p->x[p->top];
}
int isOperand(char ch) {
	if (ch >= 'A' && ch <= 'Z')
		return 1;
	else return 0;
}
void convert(char* ch) {
	STACK st;
	int i = 0;
	int cnt = 0;
	init(&st);
	st.x = (char*)malloc(sizeof(char) * (strlen(ch) + 1));

	while (i < strlen(ch)) {
		if (isOperand(ch[i])) {
			printf("%c", ch[i]);
			cnt = 1;
		}
		else if (ch[i] == '(') {
			push(&st, ch[i]);
			cnt = 1;
		}
		else if (ch[i] == ')') {
			while (st.x[st.top] != '(')
				printf("%c", pop(&st));
			pop(&st);
			cnt = 1;
		}
		else {
			if (cnt == 0) {
				if (ch[i] == '+')
					push(&st, 'p');
				else if (ch[i] == '-')
					push(&st, 'n');
				else
					cnt++;
			}
			if (cnt != 0) {
				while ((st.top != -1) && (order(ch[i]) <= order(peek(&st)))) {
					if (st.x[st.top] == 'p')
						st.x[st.top] = '+';
					if (st.x[st.top] == 'n')
						st.x[st.top] = '-';

					printf("%c", pop(&st));
				}
				push(&st, ch[i]);
				if (ch[i] == ch[i + 1]) {
					push(&st, ch[i]);
					i++;
				}
				cnt = 0;
			}
		}
		i++;
	}
	while (st.top != -1)
		printf("%c", pop(&st));
	
}
int order(char ch) {
	switch (ch) {
	case '!': case 'p' : case 'n':
		return 6;
	case '*': case '/':
		return 5;
	case '+': case '-':
		return 4;
	case '>': case '<':
		return 3;
	case '&':
		return 2;
	case '|':
		return 1;
	default:
		return -1;
	}
}
*/
