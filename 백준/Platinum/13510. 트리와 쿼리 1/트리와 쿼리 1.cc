#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100001;
//const int SZ = 10;

int N, M, cnt;
vector <pii> tree[SZ];
vector <pii> graph[SZ];
int parent[SZ], level[SZ], sz[SZ], head[SZ], mark[SZ];
vector <int> seg;
pii id[SZ], edge[SZ];

void Find_Child(int node);
void DFS(int node, int lv);
void ETT(int node);
void update(int pos, int val);
int query(int a, int b);
int seg_query(int l, int r);

void solve() {
	cin >> N;
	seg.resize(2 * N + 5);

	for (int i = 1; i <= N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
		edge[i] = { a,b };
	}

	Find_Child(1);
	DFS(1, 1);

	head[1] = 1;
	ETT(1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			int idx;
			if (level[edge[b].first] > level[edge[b].second]) idx = edge[b].first;
			else idx = edge[b].second;
			update(id[idx].first, c);
		}
		else cout << query(b, c) << '\n';
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

void Find_Child(int node) {
	mark[node] = 1;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i].first;
		if (mark[next]) continue;
		graph[node].push_back(tree[node][i]);
		Find_Child(next);
	}
	return;
}

void DFS(int node, int lv) {
	sz[node] = 1;
	level[node] = lv;
	for (int i = 0; i < graph[node].size(); i++) {
		pii& next = graph[node][i];
		parent[next.first] = node;
		DFS(next.first, lv + 1);
		sz[node] += sz[next.first];
		if (sz[next.first] > sz[graph[node][0].first]) swap(next, graph[node][0]);
	}
	return;
}

void ETT(int node) {
	cnt++;
	id[node].first = cnt;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		if (i == 0) head[next] = head[node];
		else head[next] = next;
		ETT(next);
		update(id[next].first, graph[node][i].second);
	}
	id[node].second = cnt;
	return;
}

int query(int a, int b) {
	int ret = 0;
	while (head[a] != head[b]) {
		if (level[head[a]] < level[head[b]]) swap(a, b);
		int st = head[a];
		ret = max(ret, seg_query(id[st].first, id[a].first + 1));
		a = parent[st];
	}
	if (level[a] > level[b]) swap(a, b);
	ret = max(ret, seg_query(id[a].first + 1, id[b].first + 1));
	return ret;
}

void update(int pos, int val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
	return;
}

int seg_query(int l, int r) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
	}
	return ret;
}