#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int vertex;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode** Adj;
	int* count;
}Graph;

Graph* createGraph(int V) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	if (!G)
		return NULL;
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * V);
	if (!(G->Adj))
		return NULL;
	G->count = (int*)malloc(sizeof(int) * V);
	if (!(G->count))
		return NULL;
	for (i = 0; i < V; i++) {
		G->Adj[i] = NULL;
		G->count[i] = 0;
	}
	return G;
}

typedef struct {
	int size;
	ListNode* front, * rear;
}Queue;

Queue* createQueue(void) {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	if (!Q)
		return NULL;
	Q->front = NULL;
	Q->rear = NULL;
	Q->size = 0;
	return Q;
}

void EnQueue(Queue* Q, int data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->vertex = data;
	if (Q->size == 0) {
		Q->front = newNode;
		Q->rear = newNode;
	}
	else {
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
	newNode->next = NULL;
	Q->size += 1;
	return;
}

int DeQueue(Queue* Q) {
	int data;
	ListNode* temp;
	if (Q->size == 0)
		return -1;
	temp = Q->front;
	data = Q->front->vertex;
	if (Q->size == 1) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	else 
		Q->front = Q->front->next;
	Q->size -= 1;
	free(temp);
	return data;
}

void InsertGraph(Graph* G, int u, int v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->vertex = v;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	G->count[u] += 1;
	return;
}

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i < right) && (j <= right_end)) {
		if (Arr[i] <= Arr[j]) {
			temp[pos] = Arr[i];
			i++;
			pos++;
		}
		else {
			temp[pos] = Arr[j];
			j++;
			pos++;
		}
	}
	while (i < right) {
		temp[pos] = Arr[i];
		i++;
		pos++;
	}
	while (j <= right_end) {
		temp[pos] = Arr[j];
		j++;
		pos++;
	}
	for (i = left; i <= right_end; i++)
		Arr[i] = temp[i];
}

void MergeSort(int Arr[], int temp[], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

int turn = 1;

void BFS(Graph* G, Queue* Q, int* mark) {
	int Vertex;
	ListNode* ptr;
	int* Arr, * temp;
	int i;	
	Vertex = DeQueue(Q);
	if (mark[Vertex] != 0)
		return;
	mark[Vertex] = turn++;
	ptr = G->Adj[Vertex];
	Arr = (int*)malloc(sizeof(int) * (G->count[Vertex]));
	if (!Arr)
		return;
	temp = (int*)malloc(sizeof(int) * (G->count[Vertex]));
	if (!temp)
		return;
	for (i = 0; i < G->count[Vertex]; i++) {
		Arr[i] = ptr->vertex;
		ptr = ptr->next;
	}
	MergeSort(Arr, temp, 0, G->count[Vertex] - 1);
	for (i = 0; i < G->count[Vertex]; i++) {
		if (mark[Arr[i]] == 0) {
			EnQueue(Q, Arr[i]);
		}
	}
	return;
}

int main(void) {
	int N, M, R;
	int i, u, v;
	Graph* G;
	Queue* Q;
	int* mark;
	scanf("%d %d %d", &N, &M, &R);
	G = createGraph(N);
	Q = createQueue();
	mark = (int*)malloc(sizeof(int) * N);
	if (!mark)
		return -1;
	for (i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		InsertGraph(G, u - 1, v - 1);
		InsertGraph(G, v - 1, u - 1);
	}
	for (i = 0; i < N; i++)
		mark[i] = 0;
	EnQueue(Q, R - 1);
	while (Q->size != 0) {
		BFS(G, Q, mark);
	}
	for (i = 0; i < N; i++)
		printf("%d\n", mark[i]);
	return 0;
}