#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
} TreeNode;
// ================ 원형큐 코드 시작 =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
void level_order(TreeNode* ptr)
{
	QueueType q;
	init_queue(&q); // 큐 초기화
	TreeNode *p = ptr, *k = ptr;
	enqueue(&q, ptr);
	while (p != NULL) {
		if (p->left != NULL) 
			enqueue(&q, p->left);
		if (p->right != NULL)
			enqueue(&q, p->right);
		if (p->left == NULL) {
			if (p->right != NULL) {
				p = k;
				p = p->left;
				continue;
			}
		}
		if (p->right == NULL) {
			if (p->left != NULL) {
				p = k;
				p = p->right;
				continue;
			}
		}
		k = p;
		p = p->left;
	}
	for (int i = q.front + 1; i <= q.rear; i++)
		printf("%d ", q.data[i]->data);
}
// 15
// 4 20
// 1 16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;
int main(void)
{
	level_order(root);
	return 0;
}
