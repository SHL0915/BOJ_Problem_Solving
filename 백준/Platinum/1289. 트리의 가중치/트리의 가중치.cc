#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
ll ans;
vector <pii> graph[100001];
ll arr[100001];

void DFS(int node, int par);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	DFS(1, -1);
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

void DFS(int node, int par) {
	ll sum = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int now = graph[node][i].first;
		ll cost = graph[node][i].second;
		if (now == par) continue;
		DFS(now, node);
		ll add_sum = (arr[now] * cost) % mod;

		ans += (sum * add_sum) % mod;
		ans %= mod;
		
		sum += add_sum;
		sum %= mod;
	}
	arr[node] = sum;
	return;
}