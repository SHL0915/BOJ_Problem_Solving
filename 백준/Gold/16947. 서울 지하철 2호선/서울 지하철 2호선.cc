#include <iostream>
using namespace std;

struct ListNode {
	ListNode* next;
	int vertex;
};

struct Graph {
	ListNode** Adj;
};

int N, u, v, dis;
int mark[3000];

Graph* createGraph(int N);
void Insert(Graph* G, int u, int v);
void ClearMark();
void DFS(Graph* G, int vertex, int depth);


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	Graph* G = createGraph(N);
	for (int i = 0; i < N; i++) {
		cin >> u >> v;
		Insert(G, u - 1, v - 1);
		Insert(G, v - 1, u - 1);
	}	
	for (int i = 0; i < N; i++) {
		ClearMark();
		DFS(G, i, 0);
		cout << dis << " ";
	}
	return 0;
}

Graph* createGraph(int N) {
	Graph* G = new Graph;
	if (!G)
		return nullptr;
	G->Adj = new ListNode * [N];
	if (!G->Adj)
		return nullptr;
	for (int i = 0; i < N; i++)
		G->Adj[i] = nullptr;
	return G;
}

void Insert(Graph* G, int u, int v) {
	ListNode* newNode = new ListNode;
	if (!newNode)
		return;
	newNode->vertex = v;
	newNode->next = G->Adj[u];
	G->Adj[u] = newNode;
	return;
}

void ClearMark() {
	for (int i = 0; i < N; i++)
		mark[i] = -1;
	return;
}

void DFS(Graph* G, int vertex, int depth) {	
	if (mark[vertex] != -1) {
		if (depth - mark[vertex] > 2) {
			dis = mark[vertex];
		}
		return;
	}
	mark[vertex] = depth;
	for (ListNode* ptr = G->Adj[vertex]; ptr != nullptr; ptr = ptr->next) {
		DFS(G, ptr->vertex, depth + 1);
	}
}