#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int vertex, distance;
}listdata;

typedef struct ListNode {
	listdata data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode** Adj;
}Graph;

Graph* createGraph(int V) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->Adj = (ListNode**)malloc(sizeof(ListNode*) * V);
	for (int i = 0; i < V; i++)
		G->Adj[i] = NULL;
	return G;
}

void Insert(Graph* G, int u, int v, int distance) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data.vertex = v;
	newNode->data.distance = distance;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	return;
}

int max;
int max_vertex;

void DFS(Graph* G, int u, int* mark, int sum) {
	ListNode* ptr;
	if (mark[u] != 0)
		return;
	mark[u] = 1;
	if (sum >= max) {
		max = sum;
		max_vertex = u;
	}
	for (ptr = G->Adj[u]; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->data.vertex] == 0) 
			DFS(G, ptr->data.vertex, mark, sum + ptr->data.distance);		
	}
}

int main(void) {
	int n, u, v, temp, distance, i, *mark;
	Graph* G;
	scanf("%d", &n);
	G = createGraph(n);
	mark = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &u, &v, &distance);
		Insert(G, u - 1, v - 1, distance);
		Insert(G, v - 1, u - 1, distance);		
	}
	for (i = 0; i < n; i++)
		mark[i] = 0;
	max = 0;
	max_vertex = 0;
	DFS(G, 0, mark, 0);	
	max = 0;
	temp = max_vertex;
	max_vertex = 0;
	for (i = 0; i < n; i++)
		mark[i] = 0;
	DFS(G, temp, mark, 0);
	printf("%d", max);
}