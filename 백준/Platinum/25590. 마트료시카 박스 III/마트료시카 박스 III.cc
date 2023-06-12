#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K, S;
vector <int> org[300005];
vector <int> tree[600005];
int in_degree[600005];
int parent[600005], level[600005];
int par[600005][21];

void DFS(int node, int p, int lv);
int LCA(int a, int b);

void solve() {
	cin >> N >> M >> K >> S;
	if (S > K) {
		cout << 0;
		return;
	}

	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			org[i].push_back(a);
			parent[a] = i;
		}
	}

	for (int i = 1; i <= N + S; i++) {
		int k; cin >> k;
		if (k > M) {
			cout << 0;
			return;
		}
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			tree[i].push_back(a);
			in_degree[a]++;
		}
	}

	int root = -1;

	for (int i = 1; i <= N + S; i++) {
		if (in_degree[i] == 0) root = i;
	}

	DFS(root, root, 0);

	for (int i = 1; i <= N; i++) {
		if (parent[i] == 0) continue;
		int lca = LCA(i, parent[i]);
		if (lca == parent[i]) continue;
		else {
			cout << 0;
			return;
		}
	}

	cout << 1;
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

void DFS(int node, int p, int lv) {
	par[node][0] = p;
	level[node] = lv;
	for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];

	for (int next : tree[node]) DFS(next, node, lv + 1);

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