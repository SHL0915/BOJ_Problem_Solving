#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
}coor;

typedef struct {
	int x, y, depth;
}listdata;

typedef struct ListNode{
	listdata data;
	struct ListNode* next;
}ListNode;

typedef struct Queue {
	ListNode* front, * rear;
	int size;
}Queue;

Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->size = 0;
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

void EnQueue(Queue* Q, coor data, int depth) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data.x = data.x;
	newNode->data.y = data.y;
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

listdata DeQueue(Queue * Q) {
	ListNode* temp = Q->front;
	listdata data = temp->data;
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

void BFS(Queue* Q, int** mark, int N, int M) {
	listdata temp = DeQueue(Q);
	coor pos;
	if (mark[temp.y][temp.x] != 0)
		return;
	mark[temp.y][temp.x] = temp.depth;
	if ((temp.x - 1 >= 0) && (mark[temp.y][temp.x - 1] == 0)) {
		pos.x = temp.x - 1;
		pos.y = temp.y;
		EnQueue(Q, pos, temp.depth + 1);
	}
	if ((temp.y - 1 >= 0) && (mark[temp.y - 1][temp.x] == 0)) {
		pos.x = temp.x;
		pos.y = temp.y - 1;
		EnQueue(Q, pos, temp.depth + 1);
	}
	if ((temp.x + 1 < M) && (mark[temp.y][temp.x + 1] == 0)) {
		pos.x = temp.x + 1;
		pos.y = temp.y;
		EnQueue(Q, pos, temp.depth + 1);
	}
	if ((temp.y + 1 < N) && (mark[temp.y + 1][temp.x] == 0)) {
		pos.x = temp.x;
		pos.y = temp.y + 1;
		EnQueue(Q, pos, temp.depth + 1);
	}
	return;
}



int main(void) {
	int M, N, i, j, k, max = 0;
	int** Arr;
	coor* pos;	
	Queue* Q = createQueue();
	scanf("%d %d", &M, &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	pos = (coor*)malloc(sizeof(coor) * M * N);
	for (i = 0; i < N; i++)
		Arr[i] = malloc(sizeof(int) * M);
	k = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &Arr[i][j]);
			if (Arr[i][j] == 1) {
				pos[k].x = j;
				pos[k].y = i;
				k++;
				Arr[i][j] = 0;
			}
		}
	}
	if (k == M * N + 1) {
		printf("0");
		return 0;
	}
	
	for (i = 0; i < k; i++)
		EnQueue(Q, pos[i], 1);

	while (Q->size != 0)
		BFS(Q, Arr, N, M);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (Arr[i][j] == 0) {
				printf("-1");
				return 0;
			}
			else if (Arr[i][j] >= max)
				max = Arr[i][j];
		}
	}

	printf("%d", max - 1);
	return 0;
}