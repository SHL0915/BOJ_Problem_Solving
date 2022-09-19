#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct ListNode {
	int vertex;
	struct ListNode* next;
}ListNode;

class Graph {
	ListNode** Adj;		
	int* mark;
public:
	Graph(int N) {
		Adj = new ListNode * [N];
		mark = new int[N];
		for (int i = 0; i < N; i++)
			Adj[i] = NULL;
	}
	
	void InsertGraph(int a, int b) {
		ListNode* newNode = new ListNode;
		newNode->vertex = a;
		newNode->next = Adj[b];
		Adj[b] = newNode;
	}

	void ClearMark(int N) {
		for (int i = 0; i < N; i++) {
			mark[i] = 0;
		}
	}

	void DFS(int vertex, int depth) {
		ListNode* ptr;
		if (mark[vertex] != 0) {
			if (depth >= 5) {
				cout << 1;
				exit(0);
			}
			return;
		}
		mark[vertex] = 1;	
		for (ptr = Adj[vertex]; ptr != NULL; ptr = ptr->next) {
			DFS(ptr->vertex, depth + 1);
		}
		mark[vertex] = 0;
	}
};

int main(void) {
	int N, M, a, b;
	cin >> N >> M;
	Graph G(N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G.InsertGraph(a, b);
		G.InsertGraph(b, a);
	}
	for (int i = 0; i < N; i++) {
		G.ClearMark(N);		
		G.DFS(i, 0);		
	}
	cout << 0;
	return 0;
}