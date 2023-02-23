#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXPLEN 100
typedef struct nodeType {
	char data;
	struct nodeType* link;
} nodeType;
typedef struct stackType {
	nodeType* top;
}stackType;
void init_stack(stackType* s) {
	s->top = NULL;
}
int is_empty(stackType* s) {
	return(s->top == NULL);
}
void push(stackType* s, char elem) {
	nodeType* temp = (nodeType*)malloc(sizeof(nodeType));
	temp->data = elem;
	temp->link = s->top;
	s->top = temp;
}
char pop(stackType* s) {
	if (is_empty(s)) {
		printf("stack underflow\n");
		exit(1);
	}
	else {
		nodeType* temp = s->top;
		char elem = temp->data;
		s->top = s->top->link;
		free(temp);
		return(elem);
	}
}
int peek(stackType* s) {
	if (is_empty(s)) {
		printf("stack underflow\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}
int main() {
	stackType s;
	int i, k, noOfexp, newop, op1, op2, len;
	char ch, exp[EXPLEN];
	scanf("%d", &noOfexp);
	for (i = 0; i < noOfexp; i++) {
		memset(exp, 0, sizeof(exp));
		while (getchar() != '\n');
		scanf("%s", &exp);
		len = strlen(exp);
		for (k = 0; k < len; k++) {
			ch = exp[k];
			if (ch >= '0' && ch <= '9')
				push(&s, ch - '0');
			else {
				op1 = pop(&s);
				op2 = pop(&s);
				switch (ch) {
				case '+': newop = op2 + op1; break;
				case '-': newop = op2 - op1; break;
				case '*': newop = op2 * op1; break;
				case '/': newop = op2 / op1; break;
				}
				push(&s, newop);
			}
		}
		printf("%d\n", pop(&s));
	}
}
