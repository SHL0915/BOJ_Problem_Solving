#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, depth;
}com;

typedef struct ListNode {
	com data;
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

void EnQueue(Queue* Q, com data, int depth) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data = data;
	newNode->data.depth = depth;
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
	com data;
	ListNode* temp = Q->front;
	data = temp->data;
	if (Q->size == 1) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	else {
		Q->front = temp->next;
	}
	Q->size--;
	free(temp);
	return data;
}

int flag = 0;

void BFS(Queue* Q, int** mark, com to, com from, int l) {
	com temp;
	com data;
	int x, y, depth;

	temp = DeQueue(Q);
	x = temp.x;
	y = temp.y;
	depth = temp.depth;
	data.depth = depth + 1;

	if (mark[y][x] != 0)
		return;
	else if ((y == to.y) && (x == to.x)) {			
		mark[y][x] = depth;
		flag = 1;
		return;
	}

	mark[y][x] = depth;

	if ((y - 1 >= 0) && (x - 2) >= 0) {
		data.x = x - 2;
		data.y = y - 1;
		EnQueue(Q, data, depth + 1);
	}
	if ((y - 2 >= 0) && (x - 1) >= 0) {
		data.x = x - 1;
		data.y = y - 2;
		EnQueue(Q, data, depth + 1);
	}
	if ((y + 1 < l) && (x - 2) >= 0) {
		data.x = x - 2;
		data.y = y + 1;
		EnQueue(Q, data, depth + 1);
	}
	if ((y + 2 < l) && (x - 1) >= 0) {
		data.x = x - 1;
		data.y = y + 2;		
		EnQueue(Q, data, depth + 1);
	}
	if ((y + 1 < l) && (x + 2) < l) {
		data.x = x + 2;
		data.y = y + 1;
		EnQueue(Q, data, depth + 1);
	}
	if ((y + 2 < l) && (x + 1) < l) {
		data.x = x + 1;
		data.y = y + 2;		
		EnQueue(Q, data, depth + 1);
	}
	if ((y - 1 >= 0) && (x + 2) < l) {
		data.x = x + 2;
		data.y = y - 1;
		EnQueue(Q, data, depth + 1);
	}
	if ((y - 2 >= 0) && (x + 1) < l) {
		data.x = x + 1;
		data.y = y - 2;
		EnQueue(Q, data, depth + 1);
	}
}

int main(void) {
	int T, l, i, j, k;
	int** mark;
	Queue* Q;
	com from, to;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &l);
		mark = (int**)malloc(sizeof(int*) * l);
		if (!mark)
			return -1;
		Q = createQueue();
		for (j = 0; j < l; j++) {
			mark[j] = (int*)malloc(sizeof(int) * l);
			for (k = 0; k < l; k++) {
				mark[j][k] = 0;
			}
		}
		scanf("%d %d", &from.x, &from.y);
		scanf("%d %d", &to.x, &to.y);

		if ((from.x == to.x) && (from.y == to.y))
			printf("0\n");
		else {			
			EnQueue(Q, from, 1);
			while (Q->size != 0) {
				if (flag == 1)
					break;
				BFS(Q, mark, to, from, l);
			}
			printf("%d\n", mark[to.y][to.x] - 1);
		}

		flag = 0;
		free(mark);
		free(Q);
	}
	return 0;
}