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
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * V);
	for (i = 0; i < V; i++)
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

int flag = 0;

void BFS(Graph* G, int u, int* mark, int color) {
	ListNode* ptr;
	if (mark[u] != 0)
		return;
	mark[u] = color;
	for (ptr = G->Adj[u]; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->vertex] == 0) {
			BFS(G, ptr->vertex, mark, color == 1 ? 2 : 1);
			if (flag == 1)
				return;
		}
		else if (mark[ptr->vertex] == color) {
			flag = 1;
			return;
		}
	}
	return;
}

int main(void) {
	int K, V, E, i, j;
	int u, v;
	Graph* G;
	int* mark;

	scanf("%d", &K);

	for (i = 0; i < K; i++) {
		flag = 0;
		scanf("%d %d", &V, &E);
		G = createGraph(V);
		mark = (int*)malloc(sizeof(int) * V);

		if ((V == 1) || (V == 2)) {
			printf("YES\n");
			continue;
		}

		for (j = 0; j < V; j++)
			mark[j] = 0;

		for (j = 0; j < E; j++) {
			scanf("%d %d", &u, &v);
			InsertGraph(G, u - 1, v - 1);
			InsertGraph(G, v - 1, u - 1);
		}

		for (j = 0; j < V; j++) {
			if (mark[j] == 0)
				BFS(G, j, mark, 1);
			if (flag == 1) {				
				break;
			}
		}

		free(G->Adj);
		free(mark);	

		if (flag == 1) {
			printf("NO\n");
			continue;
		}			
		printf("YES\n");
	}
}