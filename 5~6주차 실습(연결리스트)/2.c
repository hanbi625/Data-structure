#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int coef, exp;
	struct node* next;
}NODE;
typedef struct list {
	NODE* header;
}List;
void mlist(List*);
NODE* getnode();
void appendTerm(List*, int, int);
List addPoly(List*, List*);
int main() {
	List x, y, result;
	NODE* p;
	int n1, n2, c, e;

	mlist(&x);
	mlist(&y);
	mlist(&result);

	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(&x, c, e);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(&y, c, e);
	}
	result = addPoly(&x, &y);
	for (p = result.header->next; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);

	return 0;
}
void mlist(List* list) {
	list->header = getnode();
	list->header->next = NULL;
}
NODE* getnode() {
	NODE* node;
	node = (NODE*)malloc(sizeof(NODE));
	return node;
}
void appendTerm(List* k, int c, int e) {
	NODE* t, * p;
	t = getnode();
	t->coef = c;
	t->exp = e;
	t->next = NULL;
	p = k->header;
	while (p->next != NULL)
		p = p->next;
	p->next = t;
	p = t;
}
List addPoly(List* x, List* y) {
	List result;
	NODE* i, * j;
	int sum = 0;
	mlist(&result);
	i = x->header->next, j = y->header->next;
	while (i != NULL && j != NULL) {
		if (i->exp > j->exp) {
			appendTerm(&result, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(&result, j->coef, j->exp);
			j = j->next;
		}
		else {
			sum = i->coef + j->coef;
			if (sum != 0)
				appendTerm(&result, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(&result, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(&result, j->coef, j->exp);
		j = j->next;
	}
	return result;
}