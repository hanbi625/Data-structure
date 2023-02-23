#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree {
	int id;
	struct tree* left;
	struct tree* right;
}TREE;
void insert(TREE*, char, int);
int pathLength(TREE*, int);
int count(TREE*);
TREE* leftchild(TREE*);
TREE* rightchild(TREE*);
TREE* findid(TREE*, int);
int isExternal(TREE*);
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
	printf("%d", pathLength(&root, count(&root)));

	return 0;
}
void insert(TREE* v, char ch, int id) {
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	tree->id = id;
	tree->left = NULL;
	tree->right = NULL;
	if (ch == 'L') v->left = tree;
	if (ch == 'R') v->right = tree;
}
int isExternal(TREE* v) {
	return v->left == NULL && v->right == NULL;
}
int count(TREE* v) {
	if (v == NULL) return 0;
	else
		return 1+count(v->left) + count(v->right);
}
int pathLength(TREE* root, int n) {
	if (n == 1 || n == 0) return 0;
	int n1 = count(root->left);
	int n2 = count(root->right);
	return pathLength(root->left, n1) + pathLength(root->right, n2)
		+ n - 1;
}
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
