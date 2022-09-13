#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	int x, y;
	struct ListNode* next, *prev;
}ListNode;

typedef struct {
	ListNode* front, * rear;
	int size;
}Queue;

Queue* CreateQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
		return NULL;
	Q->size = 0;
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

void Push(Queue* Q, int x, int y) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->x = x;
	newNode->y = y;
	if (Q->size == 0) {
		Q->front = newNode;
		Q->rear = newNode;
		Q->rear->next = NULL;
		Q->front->prev = NULL;
	}
	else {
		newNode->next = Q->front;
		newNode->prev = NULL;
		Q->front-> prev = newNode;
		Q->front = newNode;
	}
	Q->size++;
	return;
}

void Pop(Queue * Q) {
	ListNode* temp;
	if (Q->size == 0)
		return;
	temp = Q->rear;
	Q->rear = temp->prev;
	Q->rear->next = NULL;
	free(temp);
	return;
}

int Dummy(int** Board, int N, int X, int direction, Queue* snake) {
	int i;
	int flag = 0;

	for (i = 1; i <= X; i++) {
		if (direction == 0)
			Push(snake, snake->front->x + 1, snake->front->y);
		else if (direction == 1)
			Push(snake, snake->front->x, snake->front->y + 1);
		else if (direction == 2)
			Push(snake, snake->front->x - 1, snake->front->y);
		else
			Push(snake, snake->front->x, snake->front->y - 1);

		if (((snake->front->x > N) || (snake->front->y > N)) || ((snake->front->x < 1) || (snake->front->y < 1))) {
			flag = 1;
			i += 1;
			break;
		}
		else if (Board[(snake->front->x) - 1][(snake->front->y) - 1] == 0) {
			Board[(snake->front->x) - 1][(snake->front->y) - 1] = 1;
			Board[(snake->rear->x) - 1][(snake->rear->y) - 1] = 0;
			Pop(snake);
		}
		else if (Board[(snake->front->x) - 1][(snake->front->y) - 1] == 2) {
			Board[(snake->front->x) - 1][(snake->front->y) - 1] = 1;
		}
		else {
			flag = 1;
			i += 1;
			break;
		}	
	}
	return flag*100 + i-1;
}

int main(void) {
	int N, K, L;
	int i, j;
	int** Board;
	int x, y, temp;
	int X, result = 0, prev_X =0;
	int direction = 0;
	char order;
	int flag = 0;
	Queue* snake = CreateQueue();

	Push(snake, 1, 1);

	scanf("%d", &N);
	scanf("%d", &K);

	Board = (int**)malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++) {
		Board[i] = (int*)malloc(sizeof(int) * N);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			Board[i][j] = 0;
		}
	}

	for (i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		Board[y - 1][x - 1] = 2;
	}

	scanf("%d", &L);

	scanf("%d %c", &X, &order);
	temp = Dummy(Board, N, X, direction, snake);
	flag = temp / 100;
	result += temp % 100;
	prev_X = X;
	if (order == 'L') {
		direction = (direction + 3) % 4;
	}
	else {
		direction = (direction + 1) % 4;
	}	

	for (i = 0; i < L-1; i++) {
		scanf("%d %c", &X, &order);

		if (flag == 0) {
			temp = Dummy(Board, N, X - prev_X, direction, snake);
			flag = temp / 100;
			result += temp % 100;
			prev_X = X;
			if (order == 'L') {
				direction = (direction + 3) % 4;
			}
			else {
				direction = (direction + 1) % 4;
			}			
		}
		else
			continue;
	}
	if (flag == 0) {
		temp = Dummy(Board, N, 10000 + N, direction, snake);
		flag = temp / 100;
		result += temp % 100;
	}
	
	printf("%d", result);
}