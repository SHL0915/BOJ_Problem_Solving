#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int SZ = 100001;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, key, cnt;
long long org, ans = INF;
vector <pair<int, pii>> graph, cand;
vector <pii> tree[SZ];
int par[SZ], level[SZ];
int parent[SZ][21], table[SZ][21], sec_table[SZ][21];

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
	cin >> N >> M;
	for (int i = 1; i <= N; i++) par[i] = i;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ w,{u,v} });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < M; i++) {
		if (cnt == N - 1) cand.push_back(graph[i]);
		else {
			int a = graph[i].second.first;
			int b = graph[i].second.second;
			int val = graph[i].first;
			if (Find(a) == Find(b)) cand.push_back(graph[i]);
			else {
				Union(a, b);
				tree[a].push_back({ b,val });
				tree[b].push_back({ a,val });
				org += val;
				cnt++;
			}
		}
	}
	pre(1, 1, 1, 0);
	sec_pre(1, 1, 0);
	for (int i = 0; i < cand.size(); i++) {
		int a = cand[i].second.first;
		int b = cand[i].second.second;
		int val = cand[i].first;
		int lca = LCA(a, b);
		int M = query(lca, a);
		if ((val - M) % 2 == 1 && M != 0) ans = min(ans, org - M + val);
		M = query(lca, b);
		if ((val - M) % 2 == 1 && M != 0) ans = min(ans, org - M + val);
		M = sec_query(lca, a);
		if ((val - M) % 2 == 1 && M != 0) ans = min(ans, org - M + val);
		M = sec_query(lca, b);
		if ((val - M) % 2 == 1 && M != 0) ans = min(ans, org - M + val);		
	}
	if (org % 2) cout << org << " " << ((ans == INF) ? -1 : ans);
	else cout << ((ans == INF) ? -1 : ans) << " " << org;
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
			if (sec_table[node][i - 1] % 2 != table[node][i] % 2) sec_table[node][i] = sec_table[node][i - 1];
			else if (sec_table[parent[node][i - 1]][i - 1] % 2 != table[node][i] % 2) sec_table[node][i] = sec_table[parent[node][i - 1]][i - 1];
			else sec_table[node][i] = 0;				
		}
		else if (sec_table[node][i - 1] == sec_table[parent[node][i - 1]][i - 1]) {
			if (sec_table[node][i - 1] % 2 != table[node][i] % 2) sec_table[node][i] = sec_table[node][i - 1];
			else sec_table[node][i] = 0;
		}
		else {
			if (sec_table[parent[node][i - 1]][i - 1] % 2 != table[node][i] % 2) sec_table[node][i] = sec_table[parent[node][i - 1]][i - 1];
			else if (sec_table[node][i - 1] % 2 != table[node][i] % 2) sec_table[node][i] = sec_table[node][i - 1];
			else sec_table[node][i] = 0;
		}
	}
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i].first == p) continue;
		sec_pre(tree[node][i].first, node, tree[node][i].second);
	}
	sec_table[node][0] = 0;
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

int sec_query(int a, int b) {
	int ret = 0;
	for (int i = 20; i >= 0; i--) {
		if (level[parent[b][i]] >= level[a]) {
			ret = max(ret, sec_table[b][i]);
			b = parent[b][i];
		}
	}
	return ret;
}