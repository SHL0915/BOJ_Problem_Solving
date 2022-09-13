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

typedef struct {
	ListNode* front, *rear;
	int size;
}Queue;

Graph* createGraph(int V) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * V);
	for (int i = 0; i < V; i++) {
		G->Adj[i] = NULL;
	}
	return G;
}

Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->size = 0;
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

void InsertGraph(Graph* G, int u, int v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data.vertex = v;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	return;
}

void EnQueue(Queue* Q, listdata data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
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

void BFS(Graph* G, Queue* Q, int* mark) {
	ListNode* ptr;
	listdata temp = DeQueue(Q);
	listdata input;
	if (mark[temp.vertex] != -1)
		return;
	mark[temp.vertex] = temp.depth;
	for (ptr = G->Adj[temp.vertex]; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->data.vertex] == -1) {
			input.vertex = ptr->data.vertex;
			input.depth = temp.depth + 1;
			EnQueue(Q, input);			
		}
	}
	return;
}

int main(void) {
	int N, M;
	int i, j, u, v, min;
	int* mark, * Arr;
	int sum;
	listdata input;
	Graph* G;
	Queue* Q = createQueue();

	scanf("%d %d", &N, &M);
	G = createGraph(N);
	mark = (int*)malloc(sizeof(int) * N);
	Arr = (int*)malloc(sizeof(int) * N);
		
	for (i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		InsertGraph(G, u-1, v-1);
		InsertGraph(G, v - 1, u - 1);
	}

	for (i = 0; i < N; i++) {
		sum = 0;
		for (j = 0; j < N; j++)
			mark[j] = -1;
		input.vertex = i;
		input.depth = 0;
		EnQueue(Q, input);
		while (Q->size != 0)
			BFS(G, Q, mark);		
		for (j = 0; j < N; j++) {
			if (mark[j] != -1)
				sum += mark[j];
		}
		Arr[i] = sum;
	}

	min = Arr[0];

	for (i = 0; i < N; i++) {		
		if (min >= Arr[i])
			min = Arr[i];
	}
	for (i = 0; i < N; i++) {
		if (min == Arr[i]) {
			printf("%d", i+1);
			break;
		}
	}
	return 0;

}