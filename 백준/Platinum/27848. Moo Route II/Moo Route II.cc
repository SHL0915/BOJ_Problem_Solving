#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
priority_queue <pair<pii, int>> graph[200001];
int delay[200001];
int ans[200001];

void Traverse(int node, int time);

void solve() {
	cin >> N >> M;
	memset(ans, INF, sizeof(ans));
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		graph[a].push({ {b, d}, c });
	}
	for (int i = 1; i <= N; i++) cin >> delay[i];
	Traverse(1, -delay[1]);
	ans[1] = 0;

	for (int i = 1; i <= N; i++) {
		if (ans[i] == INF) cout << -1 << '\n';
		else cout << ans[i] << '\n';
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

void Traverse(int node, int time) {
	ans[node] = min(ans[node], time);
	time += delay[node];

	while (graph[node].size()) {
		pair<pii, int> t = graph[node].top();
		int s = t.first.first, e = t.first.second, to = t.second;
		if (time > s) break;
		else {
			graph[node].pop();
			Traverse(to, e);
		}
	}
	return;
}