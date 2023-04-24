#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector <pii> graph[100001];
int color[100001];
int parent[100001];
int visited[100001];
int mark[100001];
vector <int> error;

void DFS(int node, int c);
void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N >> M >> K;
	memset(color, -1, sizeof(color));
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[b].push_back({ c,a });
		graph[c].push_back({ b,a });
	}

	for (int i = 1; i <= N; i++) if (visited[i] == 0) DFS(i, 0);

	for (int i = 0; i < error.size(); i++) mark[Find(error[i])] = 1;
	
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		if (Find(a) != Find(b)) cout << "Unknown\n";
		else {
			if (mark[Find(a)]) cout << "Error\n";
			else {
				if (color[a] == color[b]) cout << "Friend\n";
				else cout << "Enemy\n";
			}
		}
	}

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void DFS(int node, int c) {
	if (visited[node]) {
		if (color[node] == c) return;
		else {
			error.push_back(node);
			return;
		}
	}
	visited[node] = 1;
	color[node] = c;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		int next_c = c ^ graph[node][i].second;
		Union(node, next);
		DFS(next, next_c);
	}
	return;
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}