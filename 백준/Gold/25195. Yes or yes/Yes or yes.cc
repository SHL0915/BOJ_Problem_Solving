#include <iostream>
#include <vector>
using namespace std;

int N, M, S;
vector <int> graph[100001];
int fan[100000];
int mark[100001];

void DFS(int vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	cin >> S;
	for (int i = 0; i < S; i++) {
		cin >> fan[i];
		mark[fan[i]] = 2;
	}
	DFS(1);	
	cout << "Yes";
	return 0;
}

void DFS(int vertex) {
	if (mark[vertex] != 0) return;
	mark[vertex] = 1;
	for (int i = 0; i < graph[vertex].size(); i++) DFS(graph[vertex][i]);
	if (graph[vertex].size() == 0) {
		cout << "yes";
		exit(0);
	}
	return;
}