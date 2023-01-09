#include <bits/stdc++.h>
using namespace std;

int N, M, new_node, Q;
int parent[200001];
int sz[200001];
int temp[200001];
vector <pair<int, pair<int, int>>> graph;
vector <int> tree[200001];
int par[200001][21];
int level[200001];
int mark[200001];

int Find(int node);
void Union(int A, int B, int C);
void pre(int node, int p, int lv);
int LCA(int A, int B);


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= 2 * N; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c,{a,b} });
	}
	sort(graph.begin(), graph.end());
	new_node = N + 1;
	for (int i = 0; i < M; i++) {
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		a = Find(a); b = Find(b);
		if (a == b) continue;
		Union(a, b, new_node);
		sz[new_node] = sz[a] + sz[b];
		temp[new_node] = graph[i].first;
		new_node++;
	}
	for (int i = new_node - 1; i >= 1; i--) {
		if (mark[i] == 0) pre(i, i, 1);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		if (Find(a) != Find(b)) cout << -1 << '\n';
		else {
			int lca = LCA(a, b);
			cout << temp[lca] << " " << sz[lca] << '\n';
		}
	}
	return 0;
}

int Find(int node) {
	if (parent[node] == node) return parent[node];
	else return parent[node] = Find(parent[node]);
}

void Union(int A, int B, int C) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	parent[A] = C;
	parent[B] = C;
	tree[A].push_back(C);
	tree[C].push_back(A);
	tree[B].push_back(C);
	tree[C].push_back(B);
	return;
}

void pre(int node, int p, int lv) {
	mark[node] = 1;
	level[node] = lv;
	par[node][0] = p;
	for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == p) continue;
		pre(tree[node][i], node, lv + 1);
	}
	return;
}

int LCA(int A, int B) {
	if (level[A] < level[B]) swap(A, B);
	if (level[A] != level[B]) {
		for (int i = 20; i >= 0; i--) {
			if (level[par[A][i]] >= level[B]) A = par[A][i];
		}
	}
	int ret = A;
	if (A != B) {
		for (int i = 20; i >= 0; i--) {
			if (par[A][i] != par[B][i]) {
				A = par[A][i];
				B = par[B][i];
			}
			ret = par[A][i];
		}
	}
	return ret;
}