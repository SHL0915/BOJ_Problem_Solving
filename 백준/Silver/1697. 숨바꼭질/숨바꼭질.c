#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data, depth;
}com;

typedef struct ListNode {
	int data, depth;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode* front, * rear;
	int size;
}Queue;

Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
		return NULL;
	Q->size = 0;
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

void EnQueue(Queue* Q, int data, int depth) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->depth = depth;
	newNode->next = NULL;
	if (Q->size == 0) {
		Q->front = newNode;
		Q->rear = newNode;
	}
	else {
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
	Q->size++;
	return;
}

com DeQueue(Queue* Q) {
	com result;
	ListNode* temp = Q->front;
	result.data = temp->data;
	result.depth = temp->depth;
	if (Q->size == 1) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	else {
		Q->front = temp->next;
	}
	Q->size--;
	free(temp);
	return result;
}

int flag = 0;

void BFS(Queue* Q, int* mark, int K) {
	com temp;
	int data;
	int depth;

	temp = DeQueue(Q);
	data = temp.data;
	depth = temp.depth;

	if (mark[data] != 0)
		return;
	mark[data] = depth;
	depth += 1;

	if (data == K) {
		flag = 1;
	}
	else if (data - 1 == K) {
		mark[K] = depth + 1;
		flag = 1;
	}
	else if (data + 1 == K) {
		mark[K] = depth + 1;
		flag = 1;
	}
	else if (data * 2 == K) {
		mark[K] = depth + 1;
		flag = 1;
	}

	EnQueue(Q, data - 1, depth);
	EnQueue(Q, data + 1, depth);
	if (data <= 150000) {
		EnQueue(Q, data * 2, depth);
	}

	return;
}

int main(void) {
	int N, K;
	int i;
	Queue* Q;
	int* mark;

	scanf("%d %d", &N, &K);
	Q = createQueue();
	mark = (int*)malloc(sizeof(int) * 500001);
	if (!mark)
		return -1;

	for (i = 0; i <= 500000; i++)
		mark[i] = 0;

	EnQueue(Q, N, 0);

	while (Q->size != 0) {
		BFS(Q, mark, K);
		if (flag == 1)
			break;
	}
		
	if (mark[K] == 0) {
		printf("%d", mark[K]);
	}
	else {
		printf("%d", mark[K]- 1);
	}
	return 0;
}