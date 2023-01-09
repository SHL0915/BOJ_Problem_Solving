#include <bits/stdc++.h>
using namespace std;

int N, K;
vector <pair<int, int>> tree[100001];
int level[100001];
int parent[100001][21];
long long table[100001][21];

void pre(int node, int par, int lv, int val);
int query(int a, int b);
int LCA(int a, int b);
long long dist(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back({ v,w });
		tree[v].push_back({ u,w });
	}
	pre(1, 1, 1, 0);
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;
		cout << query(u, v) << '\n';
	}
	return 0;
}

void pre(int node, int par, int lv, int val) {
	level[node] = lv;
	parent[node][0] = par;
	table[node][0] = val;
	for (int i = 1; i <= 20; i++) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
		table[node][i] = table[node][i - 1] + table[parent[node][i - 1]][i - 1];
	}
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == par) continue;
		pre(tree[node][i].first, node, lv + 1, tree[node][i].second);
	}
	return;
}

int query(int a, int b) {
	int lca = LCA(a, b);
	long long distA = dist(lca, a);
	long long distB = dist(lca, b);
	long long find = distA + distB;
	if (find % 2) return -1;
	find /= 2;
	if (find >= distA) {
		find -= distA;
		find = distB - find;
		for (int i = 20; i >= 0; i--) {
			if (table[b][i] <= find) {
				find -= table[b][i];
				b = parent[b][i];
			}
		}
		if (find) return -1;
		else return b;
	}
	else {
		find -= distB;
		find = distA - find;
		for (int i = 20; i >= 0; i--) {
			if (table[a][i] <= find) {
				find -= table[a][i];
				a = parent[a][i];
			}
		}
		if (find) return -1;
		else return a;
	}
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

long long dist(int a, int b) {
	long long ret = 0;
	for (int i = 20; i >= 0; i--) {
		if (level[parent[b][i]] >= level[a]) {
			ret += table[b][i];
			b = parent[b][i];
		}
	}
	return ret;
}