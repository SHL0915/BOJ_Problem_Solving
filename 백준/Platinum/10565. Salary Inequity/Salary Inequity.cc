#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct segnode {
	ll M = 0, m = INF;
};

int N, cnt, Q;
vector <int> tree[1000005];
pii id[1000005];
int arr[1000005];
vector <segnode> seg;
vector <int> lazy;

void init();
void DFS(int node);
void update(int node, int start, int end, int left, int right, int val);
void update_lazy(int node, int start, int end);
segnode query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	init();
	for (int i = 2; i <= N; i++) {
		int a; cin >> a;
		tree[a].push_back(i);
	}

	for (int i = 1; i <= N; i++) cin >> arr[i];

	DFS(1);

	for (int i = 1; i <= N; i++) update(1, 1, N, id[i].first, id[i].first, arr[i]);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		char c; cin >> c;
		if (c == 'Q') {
			int a; cin >> a;
			segnode ans = query(1, 1, N, id[a].first, id[a].second);
			cout << ans.M - ans.m << '\n';
		}
		else {
			int a, b;
			cin >> a >> b;
			update(1, 1, N, id[a].first, id[a].second, b);
		}
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
	cin >> t;
	while (t--) solve();
	return 0;
}

void init() {
	for (int i = 1; i <= N; i++) tree[i].clear();
	cnt = 0;
	seg.clear();
	seg.resize(4 * N + 5);
	lazy.clear();
	lazy.resize(4 * N + 5);
}

void DFS(int node) {
	id[node].first = ++cnt;
	for (int next : tree[node]) DFS(next);
	id[node].second = cnt;
}

void update(int node, int start, int end, int left, int right, int val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	else if (left <= start && end <= right) {
		lazy[node] += val;
		update_lazy(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node].M = max(seg[node * 2].M, seg[node * 2 + 1].M);
	seg[node].m = min(seg[node * 2].m, seg[node * 2 + 1].m);

	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		seg[node].M += lazy[node];
		if (seg[node].m == INF) seg[node].m = lazy[node];
		else seg[node].m += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

segnode query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) {
		segnode ret = { 0,INF };
		return ret;
	}
	else if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;

	segnode l = query(node * 2, start, mid, left, right);
	segnode r = query(node * 2 + 1, mid + 1, end, left, right);

	segnode ret;
	ret.M = max(l.M, r.M);
	ret.m = min(l.m, r.m);
	return ret;
}