#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
vector <int> graph[200005];
int degree[200005], mark[200005];

void DFS(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) continue;
		if (mark[i] == 0) {
			ans++;
			cnt = 0;
			DFS(i);
			if (cnt > 2) ans += (cnt - 2) / 2;
		}
	}

	cout << ans;
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

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;

	if (degree[node] % 2) cnt++;

	for (int next : graph[node]) DFS(next);
	
	return;
}