#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt;
int arr[1000005], parent[1000005];
vector <int> tree[1000005];
pii id[1000005];
int seg[2000005];

void DFS(int node, int par);
void update(int pos, int val);
int query(int l, int r);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, 1);

	for (int i = 1; i <= N; i++) update(id[i].first, arr[i]);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int val = 0;
		for (int child : tree[i]) {
			if (child == parent[i]) continue;
			val += query(id[child].first, id[child].second + 1);
		}
		val += max(query(1, id[i].first), query(id[i].second + 1, N + 1));
		ans = max(ans, val);
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
	parent[node] = par;
	id[node].first = ++cnt;

	for (int next : tree[node]) {
		if (next == par) continue;
		DFS(next, node);
	}

	id[node].second = cnt;
	return;
}

void update(int pos, int val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
	return;
}

int query(int l, int r) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
	}

	return ret;
}