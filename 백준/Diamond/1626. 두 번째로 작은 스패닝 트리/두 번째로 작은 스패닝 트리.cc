#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int SZ = 50001;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int V, E, cnt;
long long org, ans = INF;
vector <pair<int, pii>> graph, cand;
int par[SZ];
vector <pii> tree[SZ];
int parent[SZ][21];
int level[SZ];
int table[SZ][21];
int sec_table[SZ][21];

int Find(int a);
void Union(int a, int b);
void pre(int node, int p, int lv, int val);
void sec_pre(int node, int p, int val);
int LCA(int a, int b);
int query(int a, int b);
int sec_query(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) par[i] = i;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ w,{u,v} });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < E; i++) {
		if (cnt == V - 1) cand.push_back(graph[i]);
		else {
			int a = graph[i].second.first;
			int b = graph[i].second.second;
			int val = graph[i].first;
			if (Find(a) == Find(b)) cand.push_back(graph[i]);
			else {
				Union(a, b);
				tree[a].push_back({ b,val });
				tree[b].push_back({ a, val });
				org += val;
				cnt++;
			}
		}
	}
	if (cnt != V - 1) {
		cout << -1 << '\n';
		return 0;
	}
	memset(table, -1, sizeof(table));
	memset(sec_table, -1, sizeof(sec_table));
	pre(1, 1, 1, -1);
	sec_pre(1, 1, -1);
	for (int i = 0; i < cand.size(); i++) {		
		int a = cand[i].second.first;
		int b = cand[i].second.second;
		int lca = LCA(a, b);
		int val = cand[i].first;
		int M = query(lca, a);
		if (M != val && M != -1) ans = min(ans, org - M + val);		
		M = query(lca, b);
		if (M != val && M != -1) ans = min(ans, org - M + val);		
		M = sec_query(lca, a);
		if (M != val && M != -1) ans = min(ans, org - M + val);		
		M = sec_query(lca, b);
		if (M != val && M != -1) ans = min(ans, org - M + val);		
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

int Find(int a) {
	if (a == par[a]) return par[a];
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

void sec_pre(int node, int p, int val) {
	sec_table[node][0] = val;
	for (int i = 1; i <= 20; i++) {
		if (sec_table[node][i - 1] > sec_table[parent[node][i - 1]][i - 1]) {
			if (sec_table[node][i - 1] != table[node][i]) sec_table[node][i] = sec_table[node][i - 1];
			else sec_table[node][i] = sec_table[parent[node][i - 1]][i - 1];
		}
		else if (sec_table[node][i - 1] == sec_table[parent[node][i - 1]][i - 1]) {
			if (sec_table[node][i - 1] != table[node][i]) sec_table[node][i] = sec_table[node][i - 1];
			else sec_table[node][i] = -1;
		}
		else {
			if (sec_table[parent[node][i - 1]][i - 1] != table[node][i]) sec_table[node][i] = sec_table[parent[node][i - 1]][i - 1];
			else sec_table[node][i] = sec_table[node][i - 1];
		}
	}
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == p) continue;
		sec_pre(tree[node][i].first, node, tree[node][i].second);
	}
	sec_table[node][0] = -1;
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
	int ret = -1;
	for (int i = 20; i >= 0; i--) {
		if (level[parent[b][i]] >= level[a]) {
			ret = max(ret, table[b][i]);
			b = parent[b][i];
		}
	}
	return ret;
}

int sec_query(int a, int b) {
	int ret = -1;
	for (int i = 20; i >= 0; i--) {
		if (level[parent[b][i]] >= level[a]) {
			ret = max(ret, sec_table[b][i]);
			b = parent[b][i];
		}
	}
	return ret;
}