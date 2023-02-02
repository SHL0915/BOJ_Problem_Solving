#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, V;
vector <int> graph[1001];
int mark[1001];
queue <int> q;

void DFS(int node);
void BFS();

void solve() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
	DFS(V);
	cout << '\n';
	memset(mark, 0, sizeof(mark));
	q.push(V);
	while (q.size()) BFS();
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	cout << node << " ";
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	return;
}

void BFS() {
	int node = q.front();
	q.pop();
	if (mark[node]) return;
	mark[node] = 1;
	cout << node << " ";
	for (int i = 0; i < graph[node].size(); i++) q.push(graph[node][i]);
	return;
}