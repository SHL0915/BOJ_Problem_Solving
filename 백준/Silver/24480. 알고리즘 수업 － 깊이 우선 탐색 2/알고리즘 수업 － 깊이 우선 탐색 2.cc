#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, R, cnt;
vector <int> graph[100001];
int mark[100001];

void DFS(int node);

void solve() {
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end(), greater<>());
	DFS(R);
	for (int i = 1; i <= N; i++) cout << mark[i] << '\n';
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
	cnt++;
	mark[node] = cnt;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	return;
}