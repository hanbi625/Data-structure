#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int elem;
	struct node* next;
}NODE;
typedef struct list {
	NODE* header;
}List;
NODE* getnode();
void mlist(List*);
void add(List* x, int e);
int subset(List*, List*);
List sunion(List*, List*);
List intersect(List*, List*);
int main() {
	List A, B, C;
	NODE* p;

	mlist(&A);
	mlist(&B);

	int nA, nB, e;
	scanf("%d", &nA);
	for (int i = 0; i < nA; i++) {
		scanf("%d", &e);
		add(&A, e);
	}
	scanf("%d", &nB);
	for (int i = 0; i < nB; i++) {
		scanf("%d", &e);
		add(&B, e);
	}
	C = sunion(&A, &B);
	p = C.header->next;
	if (p == NULL)
		printf(" 0");
	else {
		for (; p != NULL; p = p->next)
			printf(" %d", p->elem);
	}
	printf("\n");
	C = intersect(&A, &B);
	p = C.header->next;
	if (p == NULL)
		printf(" 0");
	else {
		for (; p != NULL; p = p->next)
			printf(" %d", p->elem);
	}


	return 0;
}
void mlist(List* list) {
	list->header = getnode();
	list->header->next = NULL;
}
NODE* getnode() {
	NODE *node = NULL;
	node = (NODE*)malloc(sizeof(NODE));
	return node;
}
void add(List* x, int e) {
	NODE* node = NULL, *p;
	node = getnode();
	node->elem = e;
	node->next = NULL;
	p = x->header->next;
	if (x->header->next == NULL) {
		x->header->next = node;
		return;
	}
	else if (p->elem > e) {
		node->next = p;
		p = node;
		return;
	}
	else {
		while (p->next != NULL) {
			if (p->next->elem > e) {
				node->next = p->next;
				p->next = node;
				return;
			}
			p = p->next;
		}
	}
	p->next = node;
}
List sunion(List* A, List* B) {
	List C;
	NODE* a, * b, *c, *p;
	mlist(&C);
	a = A->header->next, b = B->header->next;
	p = C.header;
	while (a != NULL && b != NULL) {
		if (a->elem < b->elem) {
			c = getnode();
			c->elem = a->elem;
			c->next = NULL;
			p->next = c;
			p = p->next;
			a = a->next;
		}
		else if (a->elem > b->elem) {
			c = getnode();
			c->elem = b->elem;
			c->next = NULL;
			p->next = c;
			p = p->next;
			b = b->next;
		}
		else {
			c = getnode();
			c->elem = a->elem;
			c->next = NULL;
			p->next = c;
			p = p->next;
			a = a->next;
			b = b->next;
		}
	}
	while (a != NULL) {
		c = getnode();
		c->elem = a->elem;
		c->next = NULL;
		p->next = c;
		p = p->next;
		a = a->next;
	}
	while (b != NULL) {
		c = getnode();
		c->elem = b->elem;
		c->next = NULL;
		p->next = c;
		p = p->next;
		b = b->next;
	}
	return C;
}
List intersect(List* A, List* B) {
	List C;
	NODE* a, * b, * c, * p;
	mlist(&C);
	a = A->header->next, b = B->header->next;
	p = C.header;
	while (a != NULL & b != NULL) {
		if (a->elem < b->elem)
			a = a->next;
		else if (a->elem > b->elem)
			b = b->next;
		else {
			c = getnode();
			c->elem = a->elem;
			c->next = NULL;
			p->next = c;
			p = p->next;
			a = a->next;
			b = b->next;
		}
	}
	return C;
}
