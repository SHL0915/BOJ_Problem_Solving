#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100001;

int N, M, cnt;
vector <int> arr[SZ], graph[SZ], tree[SZ];
int mark[SZ], parent[SZ], level[SZ], sz[SZ], head[SZ], id[SZ], ans[SZ];
int seg[SZ * 2 + 5];
pair<pii, pii> query[SZ];

void Find_Child(int node);
void DFS(int node, int lv);
void ETT(int node);
void update(int pos, int val);
int query_heavy(int a, int b);
int query_seg(int l, int r);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		arr[a].push_back(i);
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	Find_Child(1);
	DFS(1, 1);

	head[1] = 1;
	ETT(1);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		query[i] = { {c,i}, {a,b} };
	}

	sort(query, query + M);

	cnt = 0;
	for (int i = 0; i < M; i++) {
		int a = query[i].first.first, idx = query[i].first.second, l = query[i].second.first, r = query[i].second.second;
		if (a != cnt) {
			for (int j = 0; j < arr[cnt].size(); j++) update(id[arr[cnt][j]], -1);
			cnt = a;
			for (int j = 0; j < arr[cnt].size(); j++) update(id[arr[cnt][j]], 1);
		}

		ans[idx] = query_heavy(l, r);
	}

	for (int i = 0; i < M; i++) cout << ans[i];
	
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
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (mark[next]) continue;
		tree[node].push_back(graph[node][i]);
		Find_Child(next);
	}
	return;
}

void DFS(int node, int lv) {
	level[node] = lv;
	sz[node] = 1;
	for (int i = 0; i < tree[node].size(); i++) {
		int& next = tree[node][i];
		parent[next] = node;
		DFS(next, lv + 1);
		sz[node] += sz[next];
		if (sz[next] > sz[tree[node][0]]) swap(next, tree[node][0]);
	}
	return;
}

void ETT(int node) {
	cnt++;
	id[node] = cnt;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (i == 0) head[next] = head[node];
		else head[next] = next;
		ETT(next);
	}
	return;
}

void update(int pos, int val) {
	for (seg[pos += N] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
	return;
}

int query_heavy(int a, int b) {
	int ret = 0;
	while (head[a] != head[b]) {
		if (level[head[a]] < level[head[b]]) swap(a, b);
		int st = head[a];
		if (query_seg(id[st], id[a] + 1)) ret = 1;
		a = parent[st];
	}
	if (level[a] > level[b]) swap(a, b);
	if (query_seg(id[a], id[b] + 1)) ret = 1;
	return ret;
}

int query_seg(int l, int r) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += seg[l++];
		if (r & 1) ret += seg[--r];
	}
	return ret;
}