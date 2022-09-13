#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, depth, flag;
}listdata;

typedef struct ListNode {
	listdata data;
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
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
}

void EnQueue(Queue* Q, listdata data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data = data;
	newNode->next = NULL;
	if (Q->size == 0)
		Q->front = newNode;
	else
		Q->rear->next = newNode;
	Q->rear = newNode;
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
	else
		Q->front = temp->next;
	Q->size--;
	free(temp);
	return data;
}

void BFS(Queue* Q, int** map, int** mark0, int** mark1, int N, int M) {
	listdata temp = DeQueue(Q);
	listdata input;
	if (temp.flag == 1) {
		if ((mark1[temp.y][temp.x] != 0) || (mark0[temp.y][temp.x] != 0))
			return;
		mark1[temp.y][temp.x] = temp.depth;
		if ((temp.x - 1 >= 0) && (map[temp.y][temp.x - 1] == 0)) {
			input = temp;
			input.x -= 1;
			input.depth += 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.y - 1 >= 0) && (map[temp.y - 1][temp.x] == 0)) {
			input = temp;
			input.y -= 1;
			input.depth += 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.x + 1 < M) && (map[temp.y][temp.x + 1] == 0)) {
			input = temp;
			input.x += 1;
			input.depth += 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.y + 1 < N) && (map[temp.y + 1][temp.x] == 0)) {
			input = temp;
			input.y += 1;
			input.depth += 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
	}
	else {		
		if (mark0[temp.y][temp.x] != 0)
			return;
		mark0[temp.y][temp.x] = temp.depth;
		mark0[temp.y][temp.x] = temp.depth;
		if ((temp.x - 1 >= 0) && (map[temp.y][temp.x - 1] == 0)) {
			input = temp;
			input.x -= 1;
			input.depth += 1;
			if (mark0[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.y - 1 >= 0) && (map[temp.y - 1][temp.x] == 0)) {
			input = temp;
			input.y -= 1;
			input.depth += 1;
			if (mark0[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.x + 1 < M) && (map[temp.y][temp.x + 1] == 0)) {
			input = temp;
			input.x += 1;
			input.depth += 1;
			if (mark0[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.y + 1 < N) && (map[temp.y + 1][temp.x] == 0)) {
			input = temp;
			input.y += 1;
			input.depth += 1;
			if (mark0[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.x - 1 >= 0) && (map[temp.y][temp.x - 1] == 1)) {
			input = temp;
			input.x -= 1;
			input.depth += 1;
			input.flag = 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.y - 1 >= 0) && (map[temp.y - 1][temp.x] == 1)) {
			input = temp;
			input.y -= 1;
			input.depth += 1;
			input.flag = 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.x + 1 < M) && (map[temp.y][temp.x + 1] == 1)) {
			input = temp;
			input.x += 1;
			input.depth += 1;
			input.flag = 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
		if ((temp.y + 1 < N) && (map[temp.y + 1][temp.x] == 1)) {
			input = temp;
			input.y += 1;
			input.depth += 1;
			input.flag = 1;
			if (mark1[input.y][input.x] == 0)
				EnQueue(Q, input);
		}
	}
}

int main(void) {
	int N, M;
	int** map, ** mark0, **mark1;
	listdata input;
	int i, j;
	char line[1001];
	Queue* Q = createQueue();


	scanf("%d %d", &N, &M);

	map = (int**)malloc(sizeof(int*) * N);
	mark0 = (int**)malloc(sizeof(int*) * N);
	mark1 = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		scanf("%s", line);
		map[i] = (int*)malloc(sizeof(int) * M);
		mark0[i] = (int*)malloc(sizeof(int) * M);
		mark1[i] = (int*)malloc(sizeof(int) * M);
		for (j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
			mark0[i][j] = 0;
			mark1[i][j] = 0;
		}
	}

	input.depth = 1;
	input.flag = 0;
	input.x = 0;
	input.y = 0;

	EnQueue(Q, input);

	while (Q->size != 0)
		BFS(Q, map, mark0, mark1, N, M);	

	if ((mark1[N - 1][M - 1] == 0) && (mark0[N - 1][M - 1] == 0))
		printf("-1");
	else {
		if (mark0[N - 1][M - 1] == 0)
			printf("%d", mark1[N - 1][M - 1]);
		else if (mark1[N-1][M-1] == 0)
			printf("%d", mark0[N - 1][M - 1]);
		else
			printf("%d", mark0[N - 1][M - 1] < mark1[N - 1][M - 1] ? mark0[N - 1][M - 1] : mark1[N - 1][M - 1]);
	}
}