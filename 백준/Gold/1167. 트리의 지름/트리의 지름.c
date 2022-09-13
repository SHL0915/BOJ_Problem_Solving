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

void Postorder(Graph* G, int u) {

}

int max = 0;
int max_index = 0;

void DFS(Graph* G, int u, int* mark, int sum) {
	ListNode* ptr;
	if (sum >= max) {
		max = sum;
		max_index = u;
	}
	mark[u] = 1;
	for (ptr = G->Adj[u]; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->data.vertex] == 0) {
			DFS(G, ptr->data.vertex, mark, sum + ptr->data.distance);
		}
	}
}


int main(void) {
	int V, i, j, u, v, distance;
	int* mark;
	Graph* G;
	scanf("%d", &V);
	G = createGraph(V);
	mark = (int*)malloc(sizeof(int) * V);
	for (i = 0; i < V; i++) {
		scanf("%d", &u);
		while (1) {
			scanf("%d", &v);
			if (v == -1)
				break;
			scanf("%d", &distance);
			Insert(G, u - 1, v - 1, distance);			
		}		
	}

	DFS(G, 0, mark, 0);
	j = max_index;
	max_index = 0;
	max = 0;
	for (i = 0; i < V; i++)
		mark[i] = 0;
	DFS(G, j, mark, 0);
	
	printf("%d", max);
}