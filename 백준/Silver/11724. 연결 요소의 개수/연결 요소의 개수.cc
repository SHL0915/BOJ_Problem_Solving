#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
vector <int> graph[1001];
int mark[1001];

void DFS(int vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) {
			cnt++;
			DFS(i);
		}
	}
	cout << cnt;
	return 0;
}

void DFS(int vertex) {
	if (mark[vertex] != 0) return;
	mark[vertex] = 1;
	for (int i = 0; i < graph[vertex].size(); i++) DFS(graph[vertex][i]);
	return;
}