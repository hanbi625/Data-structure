#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack {
	int* storage;
	int top;
}STACK;
void init(STACK*);
int pop(STACK*);
void push(STACK*, int);
void print(STACK*);
int isBigger(STACK*, STACK*);
void addBig(STACK*, STACK*, STACK*);
void subBig(STACK*, STACK*, STACK*);
int main() {
	STACK A, B, C;
	char ch[101] = { 0 };
	int op;

	init(&A);
	init(&B);
	init(&C);
	scanf("%d", &op);
	getchar();
	scanf("%s", ch);
	for (int i = 0; i < strlen(ch); i++)
		push(&A, ch[i] - '0');
	getchar();
	scanf("%s", ch);
	for (int i = 0; i < strlen(ch); i++)
		push(&B, ch[i] - '0');

	switch (op) {
	case 0:
		addBig(&A, &B, &C);
		break;
	case 1:
		subBig(&A, &B, &C);
		break;
	}
	print(&C);

	return 0;
}
void init(STACK* p) {
	p->top = -1;
	p->storage = (int*)malloc(sizeof(int) * 30);
}
int pop(STACK* p) {
	int e;
	if (p->top == -1)
		return -1;
	e = p->storage[p->top];
	p->top--;
	return e;
}
void push(STACK* p, int e) {
	if (p->top == 100)
		return;
	else {
		p->top++;
		p->storage[p->top] = e;
	}
}
int isBigger(STACK* A, STACK* B) {
	int flag = 0;
	if (A->top > B->top)
		return 1;
	else if (A->top == B->top) {
		for (int i = 0; i < A->top; i++) {
			if (A->storage[i] > B->storage[i])
				return 1;
			else if (A->storage[i] < B->storage[i])
				return 0;
		}
		return 1;
	}
	else
		return 0;
}
void addBig(STACK* A, STACK* B, STACK* C) {
	int cnt = 0, sum = 0, flag = 0;
	int tA, tB, i, iA, iB;
	tA = A->top;
	tB = B->top;
	if (isBigger(A, B)) cnt = tB;
	else cnt = tA;
	iA = tA, iB = tB;
	for (i = 0; i <= cnt; i++, iA--, iB--) {
		sum = A->storage[iA] + B->storage[iB];
		if (flag == 1) {
			sum++;
			flag = 0;
		}
		if (sum >= 10) {
			flag = 1;
			sum %= 10;
		}
		push(C, sum);
	}
	if (tA > tB)
		while (iA >= 0) {
			if (flag == 1) {
				A->storage[iA]++;
				flag = 0;
				if (A->storage[iA] >= 10) {
					flag = 1;
					A->storage[iA] %= 10;
				}
			}
			push(C, A->storage[iA]);
			iA--;
		}
	else
		while (iB >= 0) {
			if (flag == 1) {
				B->storage[iB]++;
				flag = 0;
				if (B->storage[iB] >= 10) {
					flag = 1;
					B->storage[iB] %= 10;
				}
			}
			push(C, B->storage[iB]);
			iB--;
		}
	if (flag == 1)
		push(C, 1);
}
void subBig(STACK* A, STACK* B, STACK* C) {
	int cnt, tA, tB, iA, iB, i, flag = 0, num = 0;
	int res;
	tA = A->top;
	tB = B->top;
	iA = tA, iB = tB;
	if (isBigger(A, B))
		cnt = tB;
	else {
		cnt = tA;
		num = 1;
		printf("-");
	}

	for (i = 0; i <= cnt; i++, iA--, iB--) {
		if (num == 1)
			res = B->storage[iB] - A->storage[iA];
		else
			res = A->storage[iA] - B->storage[iB];
		if (flag == 1) {
			res--;
			flag = 0;
		}
		if (res < 0) {
			flag = 1;
			res += 10;
		}
		push(C, res);
	}
	if (tA > tB)
		while (iA >= 0) {
			if (flag == 1) {
				A->storage[iA]--;
				flag = 0;
				if (A->storage[iA] < 0) {
					flag = 1;
					A->storage[iA] += 10;
				}
			}
			push(C, A->storage[iA]);
			iA--;
		}
	else
		while (iB >= 0) {
			if (flag == 1) {
				B->storage[iB]--;
				flag = 0;
				if (B->storage[iB] < 0) {
					flag = 1;
					B->storage[iB] += 10;
				}
			}
			push(C, B->storage[iB]);
			iB--;
		}
}
void print(STACK* p) {
	int i;
	for (i = p->top; i >= 0; i--)
		printf("%d", p->storage[i]);
	printf("\n");
}
