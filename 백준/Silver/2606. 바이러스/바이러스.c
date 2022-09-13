#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int vertex;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode** Adj;
}Graph;

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
	newNode->vertex = v;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	return;
}

void DFS(Graph* G, int S, int mark[]) {
	int i;
	mark[S] = 1;
	ListNode* ptr = G->Adj[S];
	for (i = 0; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->vertex] == 0)
			DFS(G, ptr->vertex, mark);
	}
	return;
}

int main(void) {
	int N, M;
	int i, u, v;
	Graph* G;
	int* mark;
	int count = 0;
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
	DFS(G, 0, mark);
	for (i = 0; i < N; i++) {
		count += mark[i];
	}
	printf("%d", count - 1);
	return 0;
}