#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
}pos;

typedef struct ListNode {
	pos* data;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode*** Adj;
}Graph;

Graph* createGraph(int N) {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->Adj = (ListNode***)malloc(sizeof(ListNode**) * N);
	for (i = 0; i < N; i++)
		G->Adj[i] = (ListNode**)malloc(sizeof(ListNode*) * N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			G->Adj[i][j] = NULL;
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

int num = 1;

void BFS(Graph* G, pos position, int** mark) {	
	pos temp;
	ListNode* ptr;
	if (mark[position.y][position.x] != 0)
		return;
	mark[position.y][position.x] = num;

	for (ptr = G->Adj[position.y][position.x]; ptr != NULL; ptr = ptr->next) {
		temp.x = ptr->data->x;
		temp.y = ptr->data->y;
		BFS(G, temp, mark);
	}
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

int main(void) {
	int** Arr;
	int N, i, j;
	char line[26];
	int** mark;	
	int* count, * temp;
	pos position, u, v;
	Graph* G;

	scanf("%d", &N);
	Arr = (int**)malloc(sizeof(int*) * N);
	mark = (int**)malloc(sizeof(int*) * N);
	G = createGraph(N);
	for (i = 0; i < N; i++) {
		Arr[i] = (int*)malloc(sizeof(int) * N);
		mark[i] = (int*)malloc(sizeof(int) * N);
	}
	for (i = 0; i < N; i++) {
		scanf("%s", line);
		for (j = 0; j < N; j++) {
			Arr[i][j] = line[j] - '0';
			mark[i][j] = 0;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (Arr[i][j] == 1) {
				if ((i - 1 >= 0) && (Arr[i - 1][j] == 1)) {
					u.x = j;
					u.y = i;
					v.x = j;
					v.y = i - 1;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}
				if ((j - 1 >= 0) && (Arr[i][j-1] == 1)) {
					u.x = j;
					u.y = i;
					v.x = j -1;
					v.y = i;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}
				if ((j + 1 < N) && (Arr[i][j + 1] == 1)) {
					u.x = j;
					u.y = i;
					v.x = j + 1;
					v.y = i;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}
				if ((i + 1 < N) && (Arr[i + 1][j] == 1)) {
					u.x = j;
					u.y = i;
					v.x = j;
					v.y = i + 1;
					InsertGraph(G, u, v);
					InsertGraph(G, v, u);
				}			
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (Arr[i][j] == 0)
				continue;
			else {
				if (mark[i][j] == 0) {
					position.x = j;
					position.y = i;
					BFS(G, position, mark);
					num += 1;
				}
			}
		}
	}
	
	num = num - 1;
	count = (int*)malloc(sizeof(int) * num);
	temp = (int*)malloc(sizeof(int) * num);

	printf("%d\n", num);
	for (i = 0; i < num; i++) {
		count[i] = 0;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (mark[i][j] == 0)
				continue;
			else {
				count[mark[i][j] - 1] ++;
			}
		}
	}

	MergeSort(count, temp, 0, num - 1);

	for (i = 0; i < num; i++) {
		printf("%d\n", count[i]);
	}


}