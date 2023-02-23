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
void binaryPreOrder(TREE*);
void binaryPostOrder(TREE*);
void inOrder(TREE*);
TREE* findid(TREE*, int);
int main() {
	TREE* root;
	int num, id;

	root = treebuild();
	scanf("%d %d", &num, &id);
	if (id >= 1 && id <= 8) {
		TREE* v = findid(root, id);
		if (num == 1)
			binaryPreOrder(v);
		if (num == 2)
			inOrder(v);
		if (num == 3)
			binaryPostOrder(v);
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
int isExternam(TREE* v) {
	return v->left == NULL && v->right == NULL;
}
TREE* leftChild(TREE* v) {
	return v->left;
}
TREE* rightChild(TREE* v) {
	return v->right;
}
void binaryPreOrder(TREE* v) {
	if (v != NULL) {
		printf(" %d", v->data);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}
void binaryPostOrder(TREE* v) {
	if (v != NULL) {
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		printf(" %d", v->data);
	}
}
void inOrder(TREE* v) {
	if (v != NULL) {
		inOrder(leftChild(v));
		printf(" %d", v->data);
		inOrder(rightChild(v));
	}
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
void binaryPreorder(TREE*);
void inOrder(TREE *);
void binaryPostorder(TREE *);
int isInternal(TREE*);
TREE* leftchild(TREE*);
TREE* rightchild(TREE*);
TREE *findid(TREE *, int);
int main() {
	int num, id;
	TREE *tree, *p;
	tree = treebuild();

	scanf("%d %d", &num, &id);
	if (id >= 1 && id <= 8) {
		p = findid(tree, id);
		switch (num) {
		case 1:
			binaryPreorder(p);
			break;
		case 2:
			inOrder(p);
			break;
		case 3:
			binaryPostorder(p);
			break;
		}
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
void binaryPreorder(TREE* v) {
	printf(" %d", v->data);
	if (isInternal(v)) {
		binaryPreorder(leftchild(v));
		binaryPreorder(rightchild(v));
	}
	else {
		if (v->left != NULL)
			binaryPreorder(leftchild(v));
		else if (v->right != NULL)
			binaryPreorder(rightchild(v));
	}
}
void binaryPostorder(TREE *v) {
	if (isInternal(v)) {
		binaryPostorder(leftchild(v));
		binaryPostorder(rightchild(v));
	}
	else {
		if (v->left != NULL)
			binaryPostorder(leftchild(v));
		else if (v->right != NULL)
			binaryPostorder(rightchild(v));
	}
	printf(" %d", v->data);
}
void inOrder(TREE *v) {
	if (isInternal(v))
		inOrder(leftchild(v));
	else
		if (v->left != NULL)
			inOrder(leftchild(v));
	printf(" %d", v->data);
	if (isInternal(v))
		inOrder(rightchild(v));
	else
		if (v->right != NULL)
			inOrder(rightchild(v));
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
