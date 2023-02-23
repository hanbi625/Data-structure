#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
	int coef;
	int exp;
	struct node* Next;
}Node;
void input(int* coef, int* exp);
Node* appendTerm(Node* k, int c, int e);
void input(int* coef, int* exp)
{
	scanf("%d %d", coef, exp);
}
Node* appendTerm(Node* k, int c, int e) {
	Node* t;
	t = (Node*)malloc(sizeof(Node));
	t->coef = c;
	t->exp = e;
	t->Next = NULL;
	k->Next = t;
	k = t;
	return k;
}
Node* subPoly(Node* x, Node* y)
{
	Node* result;
	Node* i, * j, *p;
	int num = 0;
	result = (Node*)malloc(sizeof(Node));
	i = x->Next, j = y->Next;
	p = result;
	while (i != NULL && j != NULL) {
		if (i->exp > j->exp) {
			p = appendTerm(p, i->coef, i->exp);
			i = i->Next;
		}
		else if (i->exp < j->exp) {
			p = appendTerm(p, -j->coef, j->exp);
			j = j->Next;
		}
		else {
			num = i->coef - j->coef;
			if (num != 0)
				p = appendTerm(p, num, i->exp);
			i = i->Next, j = j->Next;
		}
	}
	while (i != NULL) {
		p = appendTerm(p, i->coef, i->exp);
		i = i->Next;
	}
	while (j != NULL) {
		p = appendTerm(p, -j->coef, j->exp);
		j = j->Next;
	}

	return result;
}
void output(Node* Header) {
	Node* p, * q;
	p = Header->Next;
	while (p != NULL) {
		printf(" %d %d", p->coef, p->exp);
		q = p;
		p = p->Next;
		free(q);
	}
}
int main()
{
	int i, t;
	int coef, exp;
	char c;

	Node* Header1, * Header2, * Header3, * p;
	Header1 = (Node*)malloc(sizeof(Node));
	Header2 = (Node*)malloc(sizeof(Node));
	scanf("%d ", &t);
	p = Header1;
	for (i = 0; i < t; i++) {
		input(&coef, &exp);
		p = appendTerm(p, coef, exp);
	}
	scanf("%d ", &t);
	p = Header2;
	for (i = 0; i < t; i++) {
		input(&coef, &exp);
		p = appendTerm(p, coef, exp);
	}
	Header3 = subPoly(Header1, Header2);
	output(Header3);
	free(Header1);
	free(Header2);
	free(Header3);
	return 0;
}
