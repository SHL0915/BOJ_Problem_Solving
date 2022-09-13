#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int vertex, parent;
}listdata;

typedef struct ListNode{
	listdata data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode** Adj;
}Graph;

typedef struct {
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

void BFS(Graph* G, Queue* Q, int * mark) {
	listdata temp = DeQueue(Q);	
	listdata input;
	ListNode* ptr;
	if (mark[temp.vertex] != 0)
		return;
	mark[temp.vertex] = temp.parent;
	for (ptr = G->Adj[temp.vertex]; ptr != NULL; ptr = ptr->next) {		
		if (mark[ptr->data.vertex] == 0) {			
			input.vertex = ptr->data.vertex;
			input.parent = temp.vertex + 1;
			EnQueue(Q, input);
		}
	}
	return;
}

Graph* createGraph(int V) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->Adj = (ListNode**)malloc(sizeof(ListNode*)*V);
	for (int i = 0; i < V; i++)
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


int main(void) {
	int N, i, u, v;
	listdata data;	
	int* Arr;
	Graph* G;
	Queue* Q = createQueue();

	scanf("%d", &N);
	G = createGraph(N);
	Arr = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		InsertGraph(G, u - 1, v - 1);
		InsertGraph(G, v - 1, u - 1);
		Arr[i] = 0;
	}
	Arr[N-1] = 0;

	data.vertex = 0;
	data.parent = 1;
	EnQueue(Q, data);
	
	while (Q->size != 0)
		BFS(G, Q, Arr);

	for (i = 1; i < N; i++) {
		printf("%d\n", Arr[i]);
	}
	return 0;
}
