#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, cnt = 1;
vector <int> graph[100001];
queue <int> q;
int mark[100001];

void BFS();

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
	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
	q.push(R);
	while (q.size()) BFS();
	for (int i = 1; i <= N; i++) cout << mark[i] << '\n';
	return 0;
}

void BFS() {
	int vertex = q.front();
	q.pop();
	if (mark[vertex] != 0) return;
	mark[vertex] = cnt++;
	for (int i = 0; i < graph[vertex].size(); i++) q.push(graph[vertex][i]);
	return;
}