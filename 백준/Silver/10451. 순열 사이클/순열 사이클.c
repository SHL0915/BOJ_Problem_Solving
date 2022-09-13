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
	Graph* G = malloc(sizeof(Graph));
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * V);
	for (int i = 0; i < V; i++)
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

int count = 0;

void DFS(Graph* G, int vertex, int* mark, int start) {
	ListNode* ptr = G->Adj[vertex];
	int j;
	if ((vertex == start) && (mark[vertex] != 0)) {		
		count++;
		return;
	}
	if (mark[vertex] != 0) {		
		return;
	}
	mark[vertex] = 1;		
	for (ptr = G->Adj[vertex]; ptr != NULL; ptr = ptr->next) {
		if ((mark[ptr->vertex] == 0) || (ptr->vertex == start)) {
			DFS(G, ptr->vertex, mark, start);
		}
	}
	return;
}

int main(void) {
	int T, N, i, j;	
	int* Arr, * mark;
	Graph* G;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		count = 0;
		scanf("%d", &N);
		G = createGraph(N);
		Arr = (int*)malloc(sizeof(int) * N);
		mark = (int*)malloc(sizeof(int) * N);
		for (j = 0; j < N; j++) {
			scanf("%d", &Arr[j]);
			Arr[j] -= 1;
			mark[j] = 0;
		} 	

		for (j = 0; j < N; j++) {
			InsertGraph(G, j, Arr[j]);
		}

		for (j = 0; j < N; j++) {
			if (mark[j] == 0)
				DFS(G, j, mark, j);
		}	

		printf("%d\n", count);
		free(G->Adj);
		free(G);
		free(Arr);
		free(mark);
	}
	
}