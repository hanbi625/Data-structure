#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Set
{
	int element;
	struct Set* next;
}Set;
void appendNode(Set** head, int element);
int subset(Set* headA, Set* headB);
int main() {
	int nA, nB;
	int element;
	Set* headA = NULL;
	Set* headB = NULL;
	scanf("%d", &nA);
	for (int i = 0; i < nA; i++) {
		scanf("%d", &element);
		appendNode(&headA, element);
	}
	scanf("%d", &nB);
	for (int i = 0; i < nB; i++) {
		scanf("%d", &element);
		appendNode(&headB, element);
	}

	printf("%d", subset(headA, headB));
	return 0;
}
void appendNode(Set** head, int element)
{
	Set* node, *p;
	node = (Set*)malloc(sizeof(Set));
	node->element = element;
	node->next = NULL;
	p = *head;
	if (*head == NULL) {
		*head = node;
		return;
	}
	else if (p->element > node->element) {
			node->next = p;
			p = node;
			return;
		}
	else {
		while (p->next != NULL) {
			if (p->next->element > node->element) {
				node->next = p->next;
				p->next = node;
				return;
			}
			p = p->next;
		}
	}
	p->next = node;
		
	
}
int subset(Set* headA, Set* headB)
{
	Set* a, * b;
	int cnt = 0;
	a = headA;
	b = headB;
	if (a == NULL)
		return 0;
	else {
		while (a != NULL) {
			if (b == NULL)
				return a->element;
			else if (a->element < b->element) {
				return a->element;
			}
			else if (a->element > b->element)
				b = b->next;
			
			else {
				a = a->next;
				b = b->next;
			}
		}
	}
	return 0;
}
