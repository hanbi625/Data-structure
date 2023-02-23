#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree {
	int id;
	struct tree* left;
	struct tree* right;
}TREE;
typedef struct stack {
	TREE** st;
	int top;
}STACK;
void insert(TREE*, char, int);
void binaryinOrder(TREE*);
void init(STACK*);
void push(STACK*, TREE*);
TREE* pop(STACK*);
int isEmpty(STACK*);
TREE* leftchild(TREE*);
TREE* rightchild(TREE*);
TREE* findid(TREE*, int);
int main() {
	TREE root;
	int N, id, left, right;

	root.left = NULL;
	root.right = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &id, &left, &right);
		if (i == 0) {
			root.id = id;
			if (left != 0) insert(&root, 'L', left);
			if (right != 0) insert(&root, 'R', right);
		}
		else {
			TREE* p = findid(&root, id);
			if (left != 0) insert(p, 'L', left);
			if (right != 0) insert(p, 'R', right);
		}
	}
	binaryinOrder(&root);

	return 0;
}
void init(STACK* s) {
	s->st = (TREE*)malloc(sizeof(TREE) * 100);
	s->top = -1;
}
void push(STACK* s, TREE* p) {
	s->top++;
	s->st[s->top] = p;
}
TREE* pop(STACK* s) {
	TREE* p = NULL;
	p = s->st[s->top];
	s->top--;
	return p;
}
int isEmpty(STACK* s) {
	return s->top == -1;
}
void insert(TREE* v, char ch, int id) {
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	tree->id = id;
	tree->left = NULL;
	tree->right = NULL;
	if (ch == 'L') v->left = tree;
	if (ch == 'R') v->right = tree;
}
void binaryinOrder(TREE* v) {
	STACK S;
	TREE* p = v;
	init(&S);
	while (!isEmpty(&S) || p != NULL) {
		if (p != NULL) {
			push(&S, p);
			p = p->left;
		}
		else {
			p = pop(&S);
			printf("%d ", p->id);
			p = p->right;
		}
	}
}
/* 함수 구현 두번째
void binaryinOrder(TREE* v) {
	if (leftchild(v))
		binaryinOrder(leftchild(v));
	printf("%d ", v->id);
	if (rightchild(v))
		binaryinOrder(rightchild(v));
}
*/
TREE* leftchild(TREE* v) {
	return v->left;
}
TREE* rightchild(TREE* v) {
	return v->right;
}
TREE* findid(TREE* v, int id) {
	if (v != NULL) {
		if (v->id == id) return v;
		else {
			TREE* p = findid(leftchild(v), id);
			if (p != NULL) return p;
			p = findid(rightchild(v), id);
			if (p != NULL) return p;
		}
	}
	return NULL;
}
