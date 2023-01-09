#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int SZ = 100001;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

long long V, E, cnt, ans, Q;
vector <pair<int, pii>> graph, cand;
vector <pii> tree[SZ];
map <pii, int> m;
int par[SZ];
int parent[SZ][21];
int level[SZ];
int table[SZ][21];

int Find(int a);
void Union(int a, int b);
void pre(int node, int p, int lv, int val);
int LCA(int a, int b);
int query(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) par[i] = i;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ w,{u,v} });
		m[{min(u, v), max(u, v)}] = w;
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < E; i++) {
		if (cnt == V - 1) break;
		else {
			int a = graph[i].second.first;
			int b = graph[i].second.second;
			int val = graph[i].first;
			if (Find(a) == Find(b)) {
				cand.push_back(graph[i]);
				continue;
			}
			Union(a, b);
			tree[a].push_back({ b,val });
			tree[b].push_back({ a,val });
			ans += val;
			cnt++;
		}
	}
	pre(1, 1, 1, 0);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		int lca = LCA(u, v);
		int M = max(query(lca, u), query(lca, v));
		cout << ans + m[{u, v}] - M << '\n';
	}	
	return 0;
}

int Find(int a) {
	if (par[a] == a) return par[a];
	else return par[a] = Find(par[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) par[a] = b;
	else par[b] = a;
	return;
}

void pre(int node, int p, int lv, int val) {
	level[node] = lv;
	parent[node][0] = p;
	table[node][0] = val;
	for (int i = 1; i <= 20; i++) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
		table[node][i] = max(table[node][i - 1], table[parent[node][i - 1]][i - 1]);
	}
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == p) continue;
		pre(tree[node][i].first, node, lv + 1, tree[node][i].second);
	}
	return;
}

int LCA(int a, int b) {
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

int query(int a, int b) {
	int ret = 0;
	for (int i = 20; i >= 0; i--) {
		if (level[parent[b][i]] >= level[a]) {
			ret = max(ret, table[b][i]);
			b = parent[b][i];
		}
	}
	return ret;
}
