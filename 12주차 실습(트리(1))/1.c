#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree {
	int data, id;
	struct tree* left;
	struct tree* right;
}TREE;
TREE* treebuild();
TREE* insert(int, int, TREE*, TREE*);
void binaryPreOrder(TREE*);
TREE* findid(TREE*, int);
TREE* leftchild(TREE*);
TREE* rightchild(TREE*);
int main() {
	TREE* root;
	int id;

	root = treebuild();
	scanf("%d", &id);
	if (id >= 0 && id <= 8) {
		TREE* v = findid(root, id);
		binaryPreOrder(v);
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
	TREE* node = (TREE*)malloc(sizeof(TREE));
	node->id = id;
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}
TREE* findid(TREE* v, int id) {
	if (v != NULL) {
		if (v->id == id)
			return v;
		else {
			TREE* p = findid(leftchild(v), id);
			if (p != NULL) return p;
			p = findid(rightchild(v), id);
			if (p != NULL) return p;
		}
	}
	return NULL;
}
void binaryPreOrder(TREE* v) {
	printf("%d ", v->data);
	if (v->left != NULL) printf("%d ", v->left->data);
	if (v->right != NULL) printf("%d ", v->right->data);
}
TREE* leftchild(TREE* v) {
	return v->left;
}
TREE* rightchild(TREE* v) {
	return v->right;
}
/* 또 다른 방법...
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree {
	int data, id;
	struct tree* left;
	struct tree* right;
}TREE;
TREE* insert(int, int, TREE*, TREE*);
int isInternal(TREE*);
int isExternal(TREE*);
void binaryPreOrder(TREE*);
TREE* leftchild(TREE*);
TREE* rightchild(TREE*);
int main() {
	TREE* root;
	int id;

	TREE* f7 = insert(130, 7, NULL, NULL);
	TREE* f8 = insert(80, 8, NULL, NULL);
	TREE* f6 = insert(120, 6, f7, f8);
	TREE* f4 = insert(70, 4, NULL, NULL);
	TREE* f5 = insert(90, 5, NULL, NULL);
	TREE* f2 = insert(30, 2, f4, f5);
	TREE* f3 = insert(50, 3, NULL, f6);
	TREE* f1 = insert(20, 1, f2, f3);
	root = f1;
	scanf("%d", &id);
	if (id >= 0 && id <= 8) {
		switch (id) {
		case 1:binaryPreOrder(f1); break;
		case 2:binaryPreOrder(f2); break;
		case 3:binaryPreOrder(f3); break;
		case 4:binaryPreOrder(f4); break;
		case 5:binaryPreOrder(f5); break;
		case 6:binaryPreOrder(f6); break;
		case 7:binaryPreOrder(f7); break;
		case 8:binaryPreOrder(f8); break;
		}
	}
	else printf("-1");
	
	return 0;
}

TREE* insert(int data, int id, TREE* left, TREE* right) {
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	tree->data = data;
	tree->id = id;
	tree->left = left;
	tree->right = right;
	return tree;
}
int isInternal(TREE* v) {
	return v->left != NULL && v->right != NULL;
}
int isExternal(TREE* v) {
	return v->left == NULL && v->right == NULL;
}
TREE* leftchild(TREE* v) {
	return v->left;
}
TREE* rightchild(TREE* v) {
	return v->right;
}
void binaryPreOrder(TREE* v) {
	printf("%d ", v->data);
	if (v->left != NULL)
		printf("%d ", v->left->data);
	if (v->right != NULL)
		printf("%d ", v->right->data);
}
*/
