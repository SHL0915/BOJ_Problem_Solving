#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector <pii> graph[1001];
int arr[1001];
int table[1001];

int DP(int node, int par);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) graph[i].clear();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	memset(table, -1, sizeof(table));
	arr[1] = INF;
	int ans = DP(1, -1);
	if (ans == INF) ans = 0;
	cout << ans << '\n';
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

int DP(int node, int par) {
	int& ret = table[node];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, arr[node]);
	int sum = 0, flag = 0;;
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i].first;
		if (now == par) continue;
		arr[now] = graph[node][i].second;
		sum += DP(now, node);
		flag = 1;
	}
	if (flag) ret = min(ret, sum);
	return ret;
}