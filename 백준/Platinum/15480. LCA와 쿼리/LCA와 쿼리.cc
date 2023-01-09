#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <int> tree[100001];
int parent[100001][21];
int level[100001];

void pre(int node, int par, int lv);
int LCA(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	pre(1, 0, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int r, u, v;
		cin >> r >> u >> v;
		int lca_ru = LCA(r, u);
		int lca_rv = LCA(r, v);
		int lca_uv = LCA(u, v);
		if (lca_ru == r && lca_rv == lca_uv) cout << r << '\n';
		else if (lca_rv == r && lca_ru == lca_uv) cout << r << '\n';
		else if (lca_ru == u && lca_rv == lca_uv) cout << u << '\n';
		else if (lca_rv == v && lca_ru == lca_uv) cout << v << '\n';
		else if (lca_rv == lca_ru) cout << lca_uv << '\n';
		else if (lca_rv == lca_uv) cout << lca_ru << '\n';
		else cout << lca_rv << '\n';
	}
	return 0;
}

void pre(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == par) continue;
		pre(tree[node][i], node, lv + 1);
	}
	return;
}

int LCA(int a, int b) {
	if (a == 1 || b == 1) return 1;
	if (level[a] < level[b]) swap(a, b);
	if (level[a] != level[b]) {
		for (int i = 20; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b]) a = parent[a][i];
		}
	}
	int ret = a;
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			ret = parent[a][i];
		}
	}
	return ret;
}