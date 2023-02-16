#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, W, ans;
vector <pair<pii, int>> graph;
ll dist[501];

void Bellman_Ford();

void solve() {
	graph.clear();
	ans = 0;
	cin >> N >> M >> W;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ {a,b},c });
		graph.push_back({ {b,a},c });
	}
	for (int i = 0; i < W; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ {a,b},-c });
	}
	Bellman_Ford();
	if (ans) cout << "YES\n";
	else cout << "NO\n";
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void Bellman_Ford() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int a = graph[j].first.first;
			int b = graph[j].first.second;
			int c = graph[j].second;
			if (dist[b] > dist[a] + c) {
				if (i == N - 1) ans = 1;
				dist[b] = dist[a] + c;
			}
		}
	}
	return;
}