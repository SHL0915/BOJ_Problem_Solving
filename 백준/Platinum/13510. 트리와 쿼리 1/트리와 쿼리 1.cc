#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100001;

int N, M, cnt;
vector <pii> tree[SZ];
vector <pii> graph[SZ];
int parent[SZ], level[SZ], sz[SZ], head[SZ], mark[SZ];
vector <int> seg;
pii id[SZ], edge[SZ];

void Find_Child(int node);
void DFS(int node, int lv);
void ETT(int node);
void update(int node, int start, int end, int idx, int val);
int query(int a, int b);
int seg_query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	seg.resize(4 * N);

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
			update(1, 1, N, id[idx].first, c);
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
		update(1, 1, N, id[next].first, graph[node][i].second);
	}
	id[node].second = cnt;
	return;
}

int query(int a, int b) {
	int ret = 0;
	while (head[a] != head[b]) {
		if (level[head[a]] < level[head[b]]) swap(a, b);
		int st = head[a];
		ret = max(ret, seg_query(1, 1, N, id[st].first, id[a].first));
		a = parent[st];
	}
	if (level[a] > level[b]) swap(a, b);
	ret = max(ret, seg_query(1, 1, N, id[a].first + 1, id[b].first));
	return ret;
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		seg[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
	return;
}

int seg_query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return max(seg_query(node * 2, start, mid, left, right), seg_query(node * 2 + 1, mid + 1, end, left, right));
}