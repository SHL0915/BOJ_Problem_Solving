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

Graph* createGraph(int V) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * V);
	for (int i = 0; i < V; i++) {
		G->Adj[i] = NULL;
	}
	return G;
}

void InsertGraph(Graph* G, int u, int v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->vertex = v;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	return;
}

int flag;

void DFS(Graph* G, int vertex, int* mark) {
	ListNode* ptr;
	if (mark[vertex] != 0)
		return;
	if (flag == 1)
		mark[vertex] = 1;
	flag = 1;
	for (ptr = G->Adj[vertex]; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->vertex] == 0) {
			DFS(G, ptr->vertex, mark);
		}
	}
}

int main(void) {
	int N;
	int* mark;
	int i, j, u, v;
	Graph* G;
	scanf("%d", &N);
	mark = (int*)malloc(sizeof(int) * N);
	G = createGraph(N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &u);
			if (u == 1) {
				InsertGraph(G, i, j);
			}			
		}
	}
	for (i = 0; i < N; i++) {
		flag = 0;
		for (j = 0; j < N; j++)
			mark[j] = 0;
		DFS(G, i, mark);
		for (j = 0; j < N; j++) {
			printf("%d ", mark[j]);
		}
		printf("\n");
	}
	return 0;
}