#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int vertex;
	struct Listnode* next;
}ListNode;

typedef struct {
	ListNode** Adj;
}Graph;

Graph* createGraph(int N) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	if (!G)
		return NULL;
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * N);
	if (!G->Adj)
		return NULL;
	for (i = 0; i < N; i++)
		G->Adj[i] = NULL;
	return G;
}

void InsertGraph(Graph* G, int u, int v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
		return;
	newNode->vertex = v;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	return;
}

void DFS(Graph* G, int vertex, int* mark) {
	ListNode* ptr;
	if (mark[vertex] != 0)
		return;
	mark[vertex] = 1;

	for (ptr = G->Adj[vertex]; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->vertex] == 0) {
			DFS(G, ptr->vertex, mark);
		}
	}

	return;
}

int main(void) {
	int N, M;
	int count = 0;
	int i, u, v;
	Graph* G;
	int* mark;

	scanf("%d %d", &N, &M);
	G = createGraph(N);
	mark = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		InsertGraph(G, u - 1, v - 1);
		InsertGraph(G, v - 1, u - 1);
	}

	for (i = 0; i < N; i++)
		mark[i] = 0;
	for (i = 0; i < N; i++) {
		if (mark[i] == 0) {
			DFS(G, i, mark);
			count++;
		}
	}

	printf("%d", count);
	return 0;
}