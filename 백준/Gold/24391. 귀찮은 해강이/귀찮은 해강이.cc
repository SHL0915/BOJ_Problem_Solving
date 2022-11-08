#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt, ans, input, curr, before;
vector <int> graph[100001];
int mark[100001];

void BFS(int vertex);

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
			BFS(i);
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		curr = mark[input];
		if (i != 0 && curr != before) ans++;
		before = curr;
	}
	cout << ans;
	return 0;
}

void BFS(int vertex) {
	if (mark[vertex] != 0) return;
	mark[vertex] = cnt;
	for (int i = 0; i < graph[vertex].size(); i++) BFS(graph[vertex][i]);
	return;
}