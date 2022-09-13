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

Graph* createGraph(int N) {
	int i;
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->Adj = (ListNode**)malloc(sizeof(ListNode*) * N);
	for (i = 0; i < N; i++)
		g->Adj[i] = NULL;
	g->count = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		g->count[i] = 0;
	return g;
}

void InsertGraph(Graph* g, int u, int v) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->vertex = v;
	newNode->next = g->Adj[u];
	g->Adj[u] = newNode;
	g->count[u] += 1;
	return;
}

void Merge(int Arr[], int temp[], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while ((i < right) && (j <= right_end)) {
		if (Arr[i] >= Arr[j]) {
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

void DFS(Graph* g, int R, int* mark) {
	int* Arr, * temp;
	int i;
	ListNode* ptr = g->Adj[R];
	Arr = (int*)malloc(sizeof(int) * (g->count[R]));
	temp = (int*)malloc(sizeof(int) * (g->count[R]));

	mark[R] = turn;
	turn += 1;

	for (i = 0; i < g->count[R]; i++) {
		Arr[i] = ptr->vertex;
		ptr = ptr->next;
	}

	MergeSort(Arr, temp, 0, g->count[R] - 1);

	for (i = 0; i < g->count[R]; i++) {
		if (mark[Arr[i]] == 0)
			DFS(g, Arr[i], mark);
	}
	free(Arr);
	free(temp);
	return;
}


int main(void) {
	int N, M, R;
	int i, u, v;
	Graph* g;
	int* mark;

	scanf("%d %d %d", &N, &M, &R);
	g = createGraph(N);
	mark = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		InsertGraph(g, u - 1, v - 1);
		InsertGraph(g, v - 1, u - 1);
	}

	for (i = 0; i < N; i++)
		mark[i] = 0;

	DFS(g, R - 1, mark);

	for (i = 0; i < N; i++)
		printf("%d\n", mark[i]);

	return 0;
}