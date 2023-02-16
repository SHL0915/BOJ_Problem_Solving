#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, S, E;
vector <pair<pii, int>> graph;
vector <int> rev[51];
int mark[51];
int arr[51];
ll dist[51];

void Bellman_Ford(int start);
void DFS(int node);

void solve() {
	cin >> N >> S >> E >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ {a,b},c });
		rev[b].push_back(a);
	}
	for (int i = 0; i < N; i++) cin >> arr[i];
	DFS(E);
	Bellman_Ford(S);
	if (dist[E] == INF) cout << "gg";
	else cout << -dist[E];
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

void Bellman_Ford(int start) {
	memset(dist, INF, sizeof(dist));
	dist[start] = -arr[start];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int a = graph[j].first.first;
			int b = graph[j].first.second;
			int c = graph[j].second - arr[b];			
			if (dist[a] == INF) continue;
			if (dist[b] > dist[a] + c) {
				if (i == N - 1 && mark[a] == 1) {
					cout << "Gee";
					exit(0);
				}
				dist[b] = dist[a] + c;
			}
		}
	}
	return;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int i = 0; i < rev[node].size(); i++) DFS(rev[node][i]);
	return;
}