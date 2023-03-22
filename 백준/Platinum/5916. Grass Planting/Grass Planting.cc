#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100001;

int N, M, cnt;
vector <int> graph[SZ], tree[SZ];
int mark[SZ], level[SZ], sz[SZ], parent[SZ], head[SZ], id[SZ];
vector <int> seg, lazy;

void Find_Child(int node);
void DFS(int node, int lv);
void ETT(int node);
void update(int a, int b);
void update_lazy(int node, int start, int end);
void update_seg(int node, int start, int end, int left, int right, int val);
int query(int a, int b);
int query_seg(int node, int start, int end, int left, int right);

void solve() {
	cin >> N >> M;

	seg.resize(4 * N);
	lazy.resize(4 * N);

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
		char a;
		int b, c;
		cin >> a >> b >> c;
		if (a == 'P') update(b, c);
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
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (mark[next]) continue;
		Find_Child(next);
		tree[node].push_back(graph[node][i]);
	}
	return;
}

void DFS(int node, int lv) {
	sz[node] = 1;
	level[node] = lv;
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

void update(int a, int b) {
	while (head[a] != head[b]) {
		if (level[head[a]] < level[head[b]]) swap(a, b);
		int st = head[a];
		update_seg(1, 1, N, id[st], id[a], 1);
		a = parent[st];
	}
	if (level[a] > level[b]) swap(a, b);
	update_seg(1, 1, N, id[a] + 1, id[b], 1);
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		seg[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

void update_seg(int node, int start, int end, int left, int right, int val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] += val;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update_seg(node * 2, start, mid, left, right, val);
	update_seg(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	return;
}

int query(int a, int b) {
	int ret = 0;
	while (head[a] != head[b]) {
		if (level[head[a]] < level[head[b]]) swap(a, b);
		int st = head[a];
		ret += query_seg(1, 1, N, id[st], id[a]);
		a = parent[st];
	}
	if (level[a] > level[b]) swap(a, b);
	ret += query_seg(1, 1, N, id[a] + 1, id[b]);
	return ret;
}

int query_seg(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return(query_seg(node * 2, start, mid, left, right) + query_seg(node * 2 + 1, mid + 1, end, left, right));
}