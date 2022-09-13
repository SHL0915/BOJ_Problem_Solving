#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}pos;

typedef struct ListNode {
	pos * data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode*** Adj;
}Graph;

Graph* createGraph(int N, int M) {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	if (!G)
		return NULL;
	G->Adj = (ListNode***)malloc(sizeof(ListNode**) * M);
	for (i = 0; i < M; i++) {
		G->Adj[i] = (ListNode**)malloc(sizeof(ListNode*) * N);
	}
	for (i = 0; i < M; i++) {		
		for (j = 0; j < N; j++) {
			G->Adj[i][j] = NULL;
		}
	}
	return G;
}

void InsertGraph(Graph* G, pos u, pos v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = (pos*)malloc(sizeof(pos));
	newNode->data->x = v.x;
	newNode->data->y = v.y;
	newNode->next = G->Adj[u.y][u.x];
	G->Adj[u.y][u.x] = newNode;
	return;
}

int count = 1;

void DFS(Graph* G, pos u, int** mark) {
	ListNode* ptr;
	pos temp;
	if (mark[u.y][u.x] != 0)
		return;
	mark[u.y][u.x] = count;			
	for (ptr = G->Adj[u.y][u.x]; ptr != NULL; ptr = ptr->next) {
		if (mark[ptr->data->y][ptr->data->x] == 0)
			DFS(G, *ptr->data, mark);
	}
	return;
}


int main(void) {
	int** Arr;
	int T, M, N, K;
	int i, j, k, x, y;
	pos u, v;
	Graph* G;
	int** mark;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d %d", &M, &N, &K);
		G = createGraph(M, N);
		Arr = (int**)malloc(sizeof(int*) * N);
		mark = (int**)malloc(sizeof(int*) * N);
		for (j = 0; j < N; j++) {
			Arr[j] = (int*)malloc(sizeof(int) * M);			
			mark[j] = (int*)malloc(sizeof(int) * M);
		}
				
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {				
				Arr[j][k] = 0;
				mark[j][k] = 0;
			}			
		}
		for (j = 0; j < K; j++) {
			scanf("%d %d", &x, &y);
			Arr[y][x] = 1;
		}
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				if (Arr[j][k] == 0)
					continue;
				else {
					if ((j - 1 >= 0) && (Arr[j - 1][k] == 1)) {
						u.x = k;
						u.y = j;
						v.x = k;
						v.y = j - 1;
						InsertGraph(G, u, v);
						InsertGraph(G, v, u);
					}
					if ((k - 1 >= 0) && (Arr[j][k-1] == 1)) {
						u.x = k;
						u.y = j;
						v.x = k - 1;
						v.y = j;
						InsertGraph(G, u, v);
						InsertGraph(G, v, u);
					}
					if ((j + 1 < N) && (Arr[j + 1][k] == 1)) {
						u.x = k;
						u.y = j;
						v.x = k;
						v.y = j + 1;
						InsertGraph(G, u, v);
						InsertGraph(G, v, u);
					}
					if ((k + 1 < N) && (Arr[j][k+1] == 1)) {
						u.x = k;
						u.y = j;
						v.x = k + 1;
						v.y = j;
						InsertGraph(G, u, v);
						InsertGraph(G, v, u);
					}
				}
			}
		}

		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				if (Arr[j][k] == 0)
					continue;
				else {
					if (mark[j][k] == 0) {
						u.x = k;
						u.y = j;
						DFS(G, u, mark);
						count++;
					}
				}					
			}
		}
		printf("%d\n", count - 1);
		count = 1;
		free(G -> Adj);
		free(G);
		free(Arr);
		free(mark);
	}
}