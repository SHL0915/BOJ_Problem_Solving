#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, R, cnt = 1;
vector <int> graph[100001];
int mark[100001];

bool cmp(int A, int B) {
	return A > B;
}

void DFS(int vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end(), cmp);
	DFS(R);
	for (int i = 1; i <= N; i++) cout << mark[i] << '\n';
	return 0;
}

void DFS(int vertex) {
	if (mark[vertex] != 0) return;
	mark[vertex] = cnt++;
	for (int i = 0; i < graph[vertex].size(); i++) DFS(graph[vertex][i]);
	return;
}