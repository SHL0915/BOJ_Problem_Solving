#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, d;
}pos;

typedef struct ListNode {
	pos data;	
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode*** Adj;
}Graph;

typedef struct {
	int size;
	ListNode* front, * rear;
}Queue;

Queue* createQueue(void) {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
		return NULL;
	Q->size = 0;
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

void EnQueue(Queue* Q, pos u, int d) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data.x = u.x;
	newNode->data.y = u.y;
	newNode->data.d = d;
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

pos DeQueue(Queue* Q) {
	pos data;
	ListNode* temp;
	temp = Q->front;
	if (Q->size == 1) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	else {
		Q->front = temp->next;
	}
	Q->size--;
	data = temp->data;
	free(temp);
	return data;
}

Graph* createGraph(int N, int M) {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	if (!G)
		return NULL;
	G->Adj = (ListNode***)malloc(sizeof(ListNode**) * N);
	if (!(G->Adj))
		return NULL;
	for (i = 0; i < N; i++) {
		G->Adj[i] = (ListNode**)malloc(sizeof(ListNode*) * M);
		if (!(G->Adj[i]))
			return NULL;
		for (j = 0; j < M; j++) {
			G->Adj[i][j] = NULL;
		}
	}
	return G;
}

void InsertGraph(Graph* G, pos u, pos v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->data.x = v.x;
	newNode->data.y = v.y;
	newNode->next = G->Adj[u.y][u.x];
	G->Adj[u.y][u.x] = newNode;
	return;		
}

void BFS(Graph* G, Queue* Q, int** mark) {
	ListNode* ptr;
	pos temp;		
	temp = DeQueue(Q);
	if (mark[temp.y][temp.x] != 0)
		return;
	mark[temp.y][temp.x] = temp.d;
	for (ptr = G->Adj[temp.y][temp.x]; ptr != NULL; ptr = ptr->next) {
		EnQueue(Q, ptr->data, temp.d + 1);
	}
	
}





int main(void) {
	int** Arr, ** mark;
	char line[101];
	int N, M;
	int i, j, d;
	pos u, v;
	Graph* G;
	Queue* Q;

	scanf("%d %d", &N, &M);

	Arr = (int**)malloc(sizeof(int*) * N);
	if (!Arr)
		return -1;
	mark = (int**)malloc(sizeof(int*) * N);
	if (!mark)
		return -1;
	G = createGraph(N, M);
	Q = createQueue();

	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * M);
		if (!Arr[i])
			return -1;
		mark[i] = (int*)malloc(sizeof(int) * M);
		if (!mark[i])
			return -1;
		scanf("%s", line);
		for (j = 0; j < M; j++) {
			Arr[i][j] = line[j] - '0';
			mark[i][j] = 0;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (Arr[i][j] == 0)
				continue;
			else {
				u.x = j;
				u.y = i;
				if ((i + 1 < N) && (Arr[i + 1][j] == 1)) {
					v.x = j;
					v.y = i + 1;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}
				if ((j + 1 < N) && (Arr[i][j + 1] == 1)) {
					v.x = j + 1;
					v.y = i;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}
				if ((i - 1 >= 0) && (Arr[i - 1][j] == 1)) {
					v.x = j;
					v.y = i - 1;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}
				if ((j - 1 >= 0) && (Arr[i][j - 1] == 1)) {
					v.x = j - 1;
					v.y = i;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}
			}
		}
	}

	u.x = 0;
	u.y = 0;

	EnQueue(Q, u, 1);	

	while (Q->size != 0) {
		BFS(G, Q, mark);
	}

	printf("%d", mark[N - 1][M - 1]);
	return 0;
}