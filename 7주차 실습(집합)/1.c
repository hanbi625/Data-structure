#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE* getnode();
void add(NODE** x, int e);
int subset(NODE*, NODE*);
int main() {
	NODE *headA = NULL, *headB = NULL;

	int nA, nB, e;
	scanf("%d", &nA);
	for (int i = 0; i < nA; i++) {
		scanf("%d", &e);
		add(&headA, e);
	}
	scanf("%d", &nB);
	for (int i = 0; i < nB; i++) {
		scanf("%d", &e);
		add(&headB, e);
	}
	printf("%d\n", subset(headA, headB));

	return 0;
}
NODE* getnode() {
	NODE *node = NULL;
	node = (NODE*)malloc(sizeof(NODE));
	return node;
}
void add(NODE** x, int e) {
	NODE* node = NULL, *p;
	node = getnode();
	node->elem = e;
	node->next = NULL;
	p = *x;
	if (*x == NULL) {
		*x = node;
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
int subset(NODE* A, NODE* B) {
	NODE* a, * b;
	a = A;
	b = B;
	if (A == NULL)
		return 0;
	
	else {
		while (a != NULL) {
			if (b == NULL)
				return a->elem;
			else if (a->elem < b->elem)
				return a->elem;
			else if (a->elem > b->elem)
				b = b->next;
			else {
				a = a->next;
				b = b->next;
			}
		}
	}
	return 0;
}
