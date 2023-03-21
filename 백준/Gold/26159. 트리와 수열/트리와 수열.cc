#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
ll mod = 1000000007;

int N;
vector <int> tree[100001];
ll arr[100001];
ll sz[100001];
ll cnt[100001];

void DFS(int node, int par);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 0; i < N - 1; i++) cin >> arr[i];

	DFS(1, -1);
	
	sort(arr, arr + N - 1);
	vector <ll> val;

	for (int i = 2; i <= N; i++) val.emplace_back(cnt[i]);
	sort(val.begin(), val.end(), greater<>());

	ll ans = 0;
	for (int i = 0; i < val.size(); i++) {
		ans += (val[i] * arr[i]) % mod;
		ans %= mod;
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

void DFS(int node, int par) {
	sz[node] = 1;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		DFS(next, node);
		sz[node] += sz[next];
	}
	cnt[node] = sz[node] * (N - sz[node]);
	return;
}