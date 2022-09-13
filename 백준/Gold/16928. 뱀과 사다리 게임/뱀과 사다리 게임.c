#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int vertex, depth;
}listdata;

typedef struct ListNode {
	listdata data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode** Adj;
}Graph;

typedef struct{
	ListNode* front, * rear;
	int size;
}Queue;

Graph* createGraph(int N) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * N);
	for (i = 0; i < N; i++)
		G->Adj[i] = NULL;
	return G;
}

void InsertGraph(Graph* G, int u, int v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data.vertex = v;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	return;
}

Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
}

void EnQueue(Queue* Q, int data, int depth) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data.vertex = data;
	newNode->data.depth = depth;
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
	else {
		Q->front = temp->next;
	}
	Q->size--;
	free(temp);
	return data;
}

void BFS(Graph* G, Queue* Q, int* mark) {
	listdata temp = DeQueue(Q);
	ListNode* ptr;
	if (mark[temp.vertex] != 0)
		return;
	mark[temp.vertex] = temp.depth;
	for (ptr = G->Adj[temp.vertex]; ptr != NULL; ptr = ptr->next) {		
		if (mark[ptr->data.vertex] == 0) {
			EnQueue(Q, ptr->data.vertex, temp.depth + 1);
		}
	}
	return;
}

int main(void) {
	int N, M, i, j ,flag;
	int* Arr;
	int** ladder, ** snake;
	Graph* G;
	Queue* Q = createQueue();

	scanf("%d %d", &N, &M);
	Arr = (int*)malloc(sizeof(int) * 100);
	G = createGraph(100);
	ladder = (int**)malloc(sizeof(int*) * N);
	snake = (int**)malloc(sizeof(int*) * M);

	for (i = 0; i < 100; i++)
		Arr[i] = 0;
	for (i = 0; i < N; i++) {
		ladder[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &ladder[i][0], &ladder[i][1]);
		ladder[i][0] -= 1;
		ladder[i][1] -= 1;
	}
	for (i = 0; i < M; i++) {
		snake[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &snake[i][0], &snake[i][1]);
		snake[i][0] -= 1;
		snake[i][1] -= 1;
	}
	
	for (i = 0; i < 100; i++) {
		if (i + 1 < 100) {
			flag = 0;
			for (j = 0; j < N; j++) {
				if (ladder[j][0] == i + 1) {
					InsertGraph(G, i, ladder[j][1]);
					flag = 1;
				}
			}
			for (j = 0; j < M; j++) {
				if (snake[j][0] == i + 1) {
					InsertGraph(G, i, snake[j][1]);
					flag = 1;
				}
			}
			if (flag == 0) {
				InsertGraph(G, i, i + 1);
			}
		}
		if (i + 2 < 100) {
			flag = 0;
			for (j = 0; j < N; j++) {
				if (ladder[j][0] == i + 2) {
					InsertGraph(G, i, ladder[j][1]);
					flag = 1;
				}
			}
			for (j = 0; j < M; j++) {
				if (snake[j][0] == i + 2) {
					InsertGraph(G, i, snake[j][1]);
					flag = 1;
				}
			}
			if (flag == 0) {
				InsertGraph(G, i, i + 2);
			}
		}
		if (i + 3 < 100) {
			flag = 0;
			for (j = 0; j < N; j++) {
				if (ladder[j][0] == i + 3) {
					InsertGraph(G, i, ladder[j][1]);
					flag = 1;
				}
			}
			for (j = 0; j < M; j++) {
				if (snake[j][0] == i + 3) {
					InsertGraph(G, i, snake[j][1]);
					flag = 1;
				}
			}
			if (flag == 0) {
				InsertGraph(G, i, i + 3);
			}
		}
		if (i + 4 < 100) {
			flag = 0;
			for (j = 0; j < N; j++) {
				if (ladder[j][0] == i + 4) {
					InsertGraph(G, i, ladder[j][1]);
					flag = 1;
				}
			}
			for (j = 0; j < M; j++) {
				if (snake[j][0] == i + 4) {
					InsertGraph(G, i, snake[j][1]);
					flag = 1;
				}
			}
			if (flag == 0) {
				InsertGraph(G, i, i + 4);
			}
		}
		if (i + 5 < 100) {
			flag = 0;
			for (j = 0; j < N; j++) {
				if (ladder[j][0] == i + 5) {
					InsertGraph(G, i, ladder[j][1]);
					flag = 1;
				}
			}
			for (j = 0; j < M; j++) {
				if (snake[j][0] == i + 5) {
					InsertGraph(G, i, snake[j][1]);
					flag = 1;
				}
			}
			if (flag == 0) {
				InsertGraph(G, i, i + 5);
			}
		}
		if (i + 6 < 100) {
			flag = 0;
			for (j = 0; j < N; j++) {
				if (ladder[j][0] == i + 6) {
					InsertGraph(G, i, ladder[j][1]);
					flag = 1;
				}
			}
			for (j = 0; j < M; j++) {
				if (snake[j][0] == i + 6) {
					InsertGraph(G, i, snake[j][1]);
					flag = 1;
				}
			}
			if (flag == 0) {
				InsertGraph(G, i, i + 6);
			}
		}
	}

	EnQueue(Q, 0, 1);

	while (Q->size != 0)
		BFS(G, Q, Arr);

	printf("%d", Arr[99] - 1);
	return 0;
}