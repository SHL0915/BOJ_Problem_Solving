#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, Q;
vector <pii> tree[100005];
ll arr[100005];
ll psum[100005];
int par[100005][21], level[100005];

void pre(int node, int p, int lv);
int LCA(int a, int b);

void solve() {
	cin >> N >> Q;

	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	pre(1, 1, 1);

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		int lca = LCA(a, b);

		cout << psum[a] + psum[b] - 2 * psum[lca] << '\n';
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

void pre(int node, int p, int lv) {
	par[node][0] = p;
	level[node] = lv;
	for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];

	psum[node] = arr[node] + psum[p];

	for (pii next : tree[node]) {
		if (next.first == p) continue;
		arr[next.first] = next.second;
		pre(next.first, node, lv + 1);
	}
	
	return;
}

int LCA(int a, int b) {
	if (level[a] < level[b]) swap(a, b);
	if (level[a] != level[b]) {
		for (int i = 20; i >= 0; i--) {
			if (level[par[a][i]] >= level[b]) a = par[a][i];
		}
	}

	int ret = a;
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				a = par[a][i];
				b = par[b][i];
			}
			ret = par[a][i];
		}
	}

	return ret;
}