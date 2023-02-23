#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int id;
	struct node* pre;
	struct node* next;
}NODE;
typedef struct dequqe {
	struct node* front;
	struct node* rear;
}DEQ;
NODE* getnode();
void init(DEQ*);
void add_front(DEQ*, int);
void add_rear(DEQ*, int);
int delete_front(DEQ*);
int delete_rear(DEQ*);
void print(DEQ*);
int isEmpty(DEQ*);
int main() {
	DEQ deq;
	int n, x;
	char str[3] = { 0 };

	scanf("%d", &n);
	init(&deq);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", str);
		if (strcmp(str, "AF") == 0) {
			scanf("%d", &x);
			add_front(&deq, x);
		}
		if (strcmp(str, "AR") == 0) {
			scanf("%d", &x);
			add_rear(&deq, x);
		}
		if (strcmp(str, "DF") == 0) {
			if (isEmpty(&deq)) {
				printf("underflow\n");
				break;
			}
			delete_front(&deq);
		}
		if (strcmp(str, "DR") == 0) {
			if (isEmpty(&deq)) {
				printf("underflow\n");
				break;
			}
			delete_rear(&deq);
		}
		if (strcmp(str, "P") == 0)
			print(&deq);
	}

	return 0;
}
NODE* getnode() {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->pre = NULL;
	node->next = NULL;
	return node;
}
void init(DEQ* d) {
	d->front = NULL;
	d->rear = NULL;
}
void add_front(DEQ* d, int x) {
	NODE* p = getnode();
	p->id = x;
	if (isEmpty(d))
		d->front = d->rear = p;
	else {
		p->next = d->front;
		d->front->pre = p;
		d->front = p;
	}
}
void add_rear(DEQ* d, int x) {
	NODE* p = getnode();
	p->id = x;
	if (isEmpty(d))
		d->front = d->rear = p;
	else {
		d->rear->next = p;
		p->pre = d->rear;
		d->rear = p;
	}
}
int delete_front(DEQ* d) {
	NODE* p = d->front;
	int e = p->id;
	d->front = d->front->next;
	if (d->front == NULL)
		d->rear = NULL;
	else d->front->pre = NULL;
	free(p);
	p = NULL;
	return e;
}
int delete_rear(DEQ* d) {
	NODE* p = d->rear;
	int e = p->id;
	d->rear = d->rear->pre;
	if (d->rear == NULL)
		d->front = NULL;
	else d->rear->next = NULL;
	free(p);
	p = NULL;
	return e;
}
void print(DEQ* d) {
	NODE* p = d->front;
	while (p != NULL) {
		printf(" %d", p->id);
		p = p->next;
	}
	printf("\n");
}
int isEmpty(DEQ* d) {
	return d->front == NULL;
}
