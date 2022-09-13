#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, depth;
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
	Q->size = 0;
	Q->front = NULL;
	Q->rear = NULL;
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

void BFS(Queue* Q, int** map, int** mark, int N) {
	listdata temp = DeQueue(Q);
	listdata input;
	if (mark[temp.y][temp.x] != 0)
		return;
	mark[temp.y][temp.x] = temp.depth;
	if ((temp.x - 1 >= 0) && (map[temp.y][temp.x - 1] == 1)) {
		input = temp;
		input.x -= 1;
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}
	if ((temp.y - 1 >= 0) && (map[temp.y - 1][temp.x] == 1)) {
		input = temp;
		input.y -= 1;
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}
	if ((temp.x + 1 < N) && (map[temp.y][temp.x + 1] == 1)) {
		input = temp;
		input.x += 1;
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}
	if ((temp.y + 1 < N) && (map[temp.y + 1][temp.x] == 1)) {
		input = temp;
		input.y += 1;
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}
}

int isSeaExist(int** map, int x, int y, int N) {	
	if ((x - 1 >= 0) && (map[y][x - 1] == 0))
		return 1;
	if ((y - 1 >= 0) && (map[y - 1][x] == 0))
		return 1;
	if ((x + 1 < N) && (map[y][x + 1] == 0))
		return 1;
	if ((y + 1 < N) && (map[y + 1][x] == 0))
		return 1;
	return 0;
}

int min;
int flag;

void BFS2(Queue* Q, int** map, int** mark, int N, int island) {
	listdata temp = DeQueue(Q);
	listdata input;
	if (flag == 1)
		return;
	if ((mark[temp.y][temp.x] != 0) && (temp.depth != 0))
		return;
	if(temp.depth != 0)
		mark[temp.y][temp.x] = temp.depth;
	if ((temp.x - 1 >= 0) && (map[temp.y][temp.x - 1] == 0)) {
		input = temp;
		input.x -= 1;
		input.depth += 1;		
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}
	if ((temp.y - 1 >= 0) && (map[temp.y - 1][temp.x] == 0)) {
		input = temp;
		input.y -= 1;
		input.depth += 1;
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}
	if ((temp.x + 1 < N) && (map[temp.y][temp.x + 1] == 0)) {
		input = temp;
		input.x += 1;
		input.depth += 1;
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}
	if ((temp.y + 1 < N) && (map[temp.y + 1][temp.x] == 0)) {
		input = temp;
		input.y += 1;
		input.depth += 1;
		if (mark[input.y][input.x] == 0)
			EnQueue(Q, input);
	}

	if ((temp.x - 1 >= 0) && (map[temp.y][temp.x - 1] == 1)) {
		input = temp;
		input.x -= 1;
		if (mark[input.y][input.x] != island) {			
			if (min >= temp.depth)
				min = temp.depth;
			flag = 1;
		}
	}
	if ((temp.y - 1 >= 0) && (map[temp.y - 1][temp.x] == 1)) {
		input = temp;
		input.y -= 1;
		if (mark[input.y][input.x] != island) {			
			if (min >= temp.depth)
				min = temp.depth;
			flag = 1;
		}
	}
	if ((temp.x + 1 < N) && (map[temp.y][temp.x + 1] == 1)) {
		input = temp;
		input.x += 1;
		if (mark[input.y][input.x] != island) {			
			if (min >= temp.depth)
				min = temp.depth;
			flag = 1;
		}
	}
	if ((temp.y + 1 < N) && (map[temp.y + 1][temp.x] == 1)) {
		input = temp;
		input.y += 1;
		if (mark[input.y][input.x] != island) {			
			if (min >= temp.depth)
				min = temp.depth;
			flag = 1;
		}
	}
}


int main(void) {
	int N, i, j, k;
	int** map, ** mark;
	int island = 0;
	Queue* Q = createQueue();
	listdata input;
	

	scanf("%d", &N);
	map = (int**)malloc(sizeof(int*) * N);
	mark = (int**)malloc(sizeof(int*) * N);
	min = N * N;

	for (i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int) * N);
		mark[i] = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			mark[i][j] = 0;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				if (mark[i][j] == 0) {
					island--;
					input.x = j;
					input.y = i;
					input.depth = island;
					EnQueue(Q, input);
					while (Q->size != 0)
						BFS(Q, map, mark, N);
				}
			}
		}
	}

	for (k = island; k < 0; k++) {
		flag = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if ((mark[i][j] == k) && (isSeaExist(map, j, i, N) == 1)) {					
					input.x = j;
					input.y = i;
					input.depth = 0;
					EnQueue(Q, input);
				}
			}
		}

		while (Q->size != 0)
			BFS2(Q, map, mark, N, k);

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (mark[i][j] > 0) {
					mark[i][j] = 0;
				}
			}
		}


	}

	printf("%d", min);
	return 0;
}