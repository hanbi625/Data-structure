#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tree {
	int data;
	struct tree* left;
	struct tree* right;
}TREE;
void search(TREE*);
void insert(TREE*, char, int);
TREE* leftChild(TREE*);
TREE* rightChild(TREE*);
void binaryPreOrder(TREE*);
TREE* findid(TREE*, int);
int main() {
	TREE root;
	char ch[101] = { 0 };
	int N, id, lid, rid;

	root.left = NULL;
	root.right = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &id, &lid, &rid);
		if (i == 0) {
			root.data = id;
			if (lid != 0) insert(&root, 'L', lid);
			if (rid != 0) insert(&root, 'R', rid);
		}
		else {
			TREE* p = findid(&root, id);
			if (lid != 0) insert(p, 'L', lid);
			if (rid != 0) insert(p, 'R', rid);
		}
	}
	search(&root);

	return 0;
}
void search(TREE* root) {
	char ch[101] = { 0 };
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", ch);
		TREE* v = root;
		printf(" %d", v->data);
		for (int j = 0; j < strlen(ch); j++) {
			if (ch[j] == 'R') v = rightChild(v);
			if (ch[j] == 'L') v = leftChild(v);
			printf(" %d", v->data);
		}
		printf("\n");
	}
}
void insert(TREE* v, char ch, int id) {
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	tree->data = id;
	tree->left = NULL;
	tree->right = NULL;
	if (ch == 'R') v->right = tree;
	if (ch == 'L') v->left = tree;
}
TREE* leftChild(TREE* v) {
	return v->left;
}
TREE* rightChild(TREE* v) {
	return v->right;
}
TREE* findid(TREE* v, int id) {
	if (v != NULL) {
		if (v->data == id)
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
