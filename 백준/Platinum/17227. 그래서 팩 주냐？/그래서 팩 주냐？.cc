#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, E;
vector <int> graph[100005];
int in_degree[100005];
int table[100005][2];

int DP(int now, int type);

void solve() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		in_degree[b]++;
	}

	memset(table, -1, sizeof(table));

	int ans = INF;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) ans = min(ans, DP(i, 0));
	}

	if (ans == INF) cout << -1;
	else cout << ans;

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

int DP(int now, int type) {
	if (now == N) {
		if (type) return INF;
		else return 0;
	}
	int& ret = table[now][type];
	if (ret != -1) return ret;
	ret = INF;

	vector <int> cand;

	for (int next : graph[now]) cand.push_back({ DP(next, type ^ 1) });
	
	sort(cand.begin(), cand.end());
	
	if (type) ret = min(ret, cand[0]);
	else {
		for (int i = 0; i < cand.size(); i++) ret = min(ret, (int)cand.size() - 1 - i + cand[i]);
	}

	return ret;
}