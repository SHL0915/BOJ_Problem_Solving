#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, z;
}coor;

typedef struct {
	int x, y, z, depth;
}listdata;

typedef struct ListNode {
	listdata data;
	struct ListNode* next;
}ListNode;

typedef struct Queue {
	ListNode* front,* rear;
	int size;
}Queue;

Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
}

void EnQueue(Queue* Q, coor data, int depth) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data.x = data.x;
	newNode->data.y = data.y;
	newNode->data.z = data.z;
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

listdata DeQueue(Queue* Q) {
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

void BFS(Queue* Q, int*** mark, int N, int M, int H) {
	listdata temp = DeQueue(Q);
	coor data;
	
	if (mark[temp.z][temp.y][temp.x] != 0)
		return;
	mark[temp.z][temp.y][temp.x] = temp.depth;
	if ((temp.z - 1 >= 0) && (mark[temp.z - 1][temp.y][temp.x] == 0)) {
		data.x = temp.x;
		data.y = temp.y;
		data.z = temp.z - 1;
		EnQueue(Q, data, temp.depth + 1);
	}
	if ((temp.x - 1 >= 0) && (mark[temp.z][temp.y][temp.x - 1] == 0)) {
		data.x = temp.x - 1;
		data.y = temp.y;
		data.z = temp.z;
		EnQueue(Q, data, temp.depth + 1);
	}
	if ((temp.y - 1 >= 0) && (mark[temp.z][temp.y - 1][temp.x] == 0)) {
		data.x = temp.x;
		data.y = temp.y - 1;
		data.z = temp.z;
		EnQueue(Q, data, temp.depth + 1);
	}
	if ((temp.z + 1 < H) && (mark[temp.z + 1][temp.y][temp.x] == 0)) {
		data.x = temp.x;
		data.y = temp.y;
		data.z = temp.z + 1;
		EnQueue(Q, data, temp.depth + 1);
	}
	if ((temp.y + 1 < N) && (mark[temp.z][temp.y + 1][temp.x] == 0)) {
		data.x = temp.x;
		data.y = temp.y + 1;
		data.z = temp.z;
		EnQueue(Q, data, temp.depth + 1);
	}
	if ((temp.x + 1 < M) && (mark[temp.z][temp.y][temp.x + 1] == 0)) {
		data.x = temp.x + 1;
		data.y = temp.y;
		data.z = temp.z;
		EnQueue(Q, data, temp.depth + 1);
	}
	return;
}

int main(void) {
	int M, N, H, i, j, k, l, max = 0;
	int*** Arr;
	coor* pos;
	Queue* Q = createQueue();
	scanf("%d %d %d", &M, &N, &H);
	pos = (coor*)malloc(sizeof(coor) * M * N * H);
	Arr = (int***)malloc(sizeof(int**) * H);
	for (i = 0; i < H; i++) {
		Arr[i] = (int**)malloc(sizeof(int*) * N);
		for (j = 0; j < N; j++) {
			Arr[i][j] = (int*)malloc(sizeof(int) * M);
		}
	}
	l = 0;
	for (i = 0; i < H; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				scanf("%d", &Arr[i][j][k]);
				if (Arr[i][j][k] == 1) {
					pos[l].x = k;
					pos[l].y = j;
					pos[l].z = i;
					l++;
					Arr[i][j][k] = 0;
				}
			}
		}
	}

	if (l - 1 == M * N * H) {
		printf("0");
		return 0;
	}

	for (i = 0; i < l; i++) {
		EnQueue(Q, pos[i], 1);
	}

	while (Q->size != 0)
		BFS(Q, Arr, N, M, H);

	for (i = 0; i < H; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				if (Arr[i][j][k] == 0) {
					printf("-1");
					return 0;
				}
				else if (max <= Arr[i][j][k])
					max = Arr[i][j][k];
			}
		}
	}

	printf("%d", max - 1);
	return 0;
}