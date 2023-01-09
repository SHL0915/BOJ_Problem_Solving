#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int SZ = 200001;

int N, M, cnt;
long long ans;
vector <pair<pii, pii>> graph;
vector <pii> tree[SZ];
int par[SZ];
int mark[SZ];
int parent[SZ][21];
int level[SZ];
int table[SZ][21];

int Find(int a);
void Union(int a, int b);
void pre(int node, int p, int lv, int val);
bool cmp(pair<pii, pii> A, pair<pii, pii> B);
int LCA(int a, int b);
int query(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) par[i] = i;
 	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ {c,i},{a,b} });
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < M; i++) {
		if (cnt == N - 1) break;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		int val = graph[i].first.first;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		tree[a].push_back({ b,val });
		tree[b].push_back({ a,val });
		cnt++;
		ans += val;
		mark[graph[i].first.second] = 1;
	}
	pre(1, 1, 1, 0);
	sort(graph.begin(), graph.end(), cmp);
	for (int i = 0; i < M; i++) {
		if (mark[i] == 1) cout << ans << '\n';
		else {
			int a = graph[i].second.first;
			int b = graph[i].second.second;
			int val = graph[i].first.first;
			int lca = LCA(a, b);
			int M = max(query(lca, a), query(lca, b));
			cout << ans - M + val << '\n';
		}
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

bool cmp(pair<pii, pii> A, pair<pii, pii> B) {
	return A.first.second < B.first.second;
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