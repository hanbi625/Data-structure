#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	char e;
	struct node* pre;
	struct node* next;
}NODE;
typedef struct list {
	NODE* header;
	NODE* trailer;
}List;
void mlist(List*);
NODE* getnode();
void add(List*, int, char);
char delete(List*, int);
char get(List*, int);
void print(List*);
int main() {
	List list;
	int N, r, n = 0;
	char ch, e;

	mlist(&list);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c", &ch);
		switch (ch) {
		case 'A':
			scanf("%d %c", &r, &e);
			if (r < 1 || r> n + 1) {
				printf("invalid position\n");
				break;
			}
			add(&list, r, e);
			n++;
			break;
		case 'D':
			scanf("%d", &r);
			if (r<1 || r>n) {
				printf("invalid position\n");
				break;
			}
			delete(&list, r);
			n--;
			break;
		case 'G':
			scanf("%d", &r);
			if (r<1 || r>n) {
				printf("invalid position\n");
				break;
			}
			printf("%c\n", get(&list, r));
			break;
		case 'P':
			print(&list);
			break;
		}
	}

	return 0;
}
void mlist(List* list) {
	list->header = getnode();
	list->trailer = getnode();
	list->header->next = list->trailer;
	list->header->pre = NULL;
	list->trailer->pre = list->header;
	list->trailer->next = NULL;
}
NODE* getnode() {
	NODE* node;
	node = (NODE*)malloc(sizeof(NODE));
	return node;
}
void add(List* list, int r, char e) {
	NODE* node, * p;
	node = getnode();
	node->e = e;
	p = list->header;
	for (int i = 0; i < r; i++)
		p = p->next;
	node->pre = p->pre;
	node->next = p;
	p->pre->next = node;
	p->pre = node;
}
char delete(List* list, int r) {
	NODE* p;
	p = list->header;
	for (int i = 0; i < r; i++)
		p = p->next;
	char e = p->e;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
	return e;
}
char get(List* list, int r) {
	NODE* p;
	p = list->header;
	for (int i = 0; i < r; i++)
		p = p->next;
	return p->e;
}
void print(List* list) {
	NODE* p;
	for (p = list->header->next; p != list->trailer; p = p->next)
		printf("%c", p->e);
	printf("\n");
}
