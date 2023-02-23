#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree {
	int id, data;
	struct tree* left;
	struct tree* right;
}TREE;
TREE* treebuild();
TREE* insert(int, int, TREE*, TREE*);
int isInternal(TREE*);
int isExternal(TREE*);
TREE* leftChild(TREE*);
TREE* rightChild(TREE*);
int binaryPreOrder(TREE*);
TREE* findid(TREE*, int);
int main() {
	TREE* root;
	int id, sum;

	root = treebuild();
	scanf("%d", &id);
	if (id >= 0 && id <= 8) {
		TREE* v = findid(root, id);
		sum = binaryPreOrder(v);
		printf("%d", sum);
	}
	else printf("-1");

	return 0;
}
TREE* treebuild() {
	TREE* f7 = insert(7, 130, NULL, NULL);
	TREE* f8 = insert(8, 80, NULL, NULL);
	TREE* f6 = insert(6, 120, f7, f8);
	TREE* f4 = insert(4, 70, NULL, NULL);
	TREE* f5 = insert(5, 90, NULL, NULL);
	TREE* f2 = insert(2, 30, f4, f5);
	TREE* f3 = insert(3, 50, NULL, f6);
	TREE* f1 = insert(1, 20, f2, f3);
	return f1;
}
TREE* insert(int id, int data, TREE* left, TREE* right) {
	TREE* v = (TREE*)malloc(sizeof(TREE));
	v->id = id;
	v->data = data;
	v->left = left;
	v->right = right;
	return v;
}
int isInternal(TREE* v) {
	return (v->left != NULL) && (v->right != NULL);
}
int isExternal(TREE* v) {
	return v->left == NULL && v->right == NULL;
}
TREE* leftChild(TREE* v) {
	return v->left;
}
TREE* rightChild(TREE* v) {
	return v->right;
}
int binaryPreOrder(TREE* v) {
	int sum = 0;
	if (v != NULL) {
		sum += v->data;
		sum += binaryPreOrder(leftChild(v));
		sum += binaryPreOrder(rightChild(v));
	}
	return sum;
}
TREE* findid(TREE* v, int id) {
	if (v != NULL) {
		if (v->id == id)
			return v;
		else {
			TREE* p = findid(leftChild(v), id);
			if (p != NULL) return p;
			p = findid(rightChild(v), id);
			if (p != NULL) return p;
		}
	}
	return NULL;
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree {
	int data;
	int id;
	struct tree* left;
	struct tree* right;
}TREE;
TREE *treebuild();
TREE* insert(int, int, TREE*, TREE*);
int binaryPreorder(TREE*);
int isInternal(TREE*);
TREE* leftchild(TREE*);
TREE* rightchild(TREE*);
TREE *findid(TREE *, int);
int main() {
	int id, sum = 0;
	TREE *tree, *p;
	tree = treebuild();

	scanf("%d", &id);
	if (id >= 1 && id <= 8) {
		p = findid(tree, id);
		sum = binaryPreorder(p);
		printf("%d", sum);
	}
	else printf("-1");

	return 0;
}
TREE *treebuild() {
	TREE* f7 = insert(130, 7, NULL, NULL);
	TREE* f8 = insert(80, 8, NULL, NULL);
	TREE* f6 = insert(120, 6, f7, f8);
	TREE* f3 = insert(50, 3, NULL, f6);
	TREE* f4 = insert(70, 4, NULL, NULL);
	TREE* f5 = insert(90, 5, NULL, NULL);
	TREE* f2 = insert(30, 2, f4, f5);
	TREE* f1 = insert(20, 1, f2, f3);

	return f1;
}
TREE* insert(int elem, int id, TREE* left, TREE* right) {
	TREE* v = (TREE*)malloc(sizeof(TREE));
	v->data = elem;
	v->id = id;
	v->left = left;
	v->right = right;
	return v;
}
int binaryPreorder(TREE* v) {
	int sum = 0;
	sum += v->data;
	if (isInternal(v)) {
		sum += binaryPreorder(leftchild(v));
		sum += binaryPreorder(rightchild(v));
	}
	else {
		if (v->left != NULL)
			sum += binaryPreorder(leftchild(v));
		else if (v->right != NULL)
			sum += binaryPreorder(rightchild(v));
	}
	return sum;
}
int isInternal(TREE* v) {
	return (v->left != NULL) && (v->right != NULL);
}
TREE* leftchild(TREE* v) {
	return v->left;
}
TREE* rightchild(TREE* v) {
	return v->right;
}
TREE *findid(TREE *v, int id) {
	TREE *p = NULL;
	if (v != NULL) {
		if (v->id == id)
			return v;
		p = findid(leftchild(v), id);
		if (p != NULL) return p;
		p = findid(rightchild(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}
*/
