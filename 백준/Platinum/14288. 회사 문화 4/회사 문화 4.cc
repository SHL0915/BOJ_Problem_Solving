#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, id;
vector <int> graph[100001];
pii ETT[100001];
ll revseg[200005];
vector <ll> seg, lazy;

void DFS(int node);
void update(int node, int start, int end, int left, int right, ll val);
void update_lazy(int node, int start, int end);
ll query(int node, int start, int end, int left, int right);
void update_rev(int pos, ll val);
ll query_rev(int l, int r);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a == -1) continue;
		graph[a].push_back(i);
	}

	DFS(1);

	seg.resize(4 * N);
	lazy.resize(4 * N);

	int mode = 0;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
			if (mode) update_rev(ETT[b].first, c);
			else update(1, 1, N, ETT[b].first, ETT[b].second, c);
		}
		else if (a == 2) {
			int b; cin >> b;
			cout << query(1, 1, N, ETT[b].first, ETT[b].first) + query_rev(ETT[b].first, ETT[b].second + 1) << '\n';
		}
		else mode ^= 1;
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

void DFS(int node) {
	id++;
	ETT[node].first = id;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	ETT[node].second = id;
	return;
}

void update(int node, int start, int end, int left, int right, ll val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] += val;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		seg[node] += lazy[node] * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

ll query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update_rev(int pos, ll val) {
	for (revseg[pos += N] += val; pos > 0; pos >>= 1) revseg[pos >> 1] = revseg[pos] + revseg[pos ^ 1];
	return;
}

ll query_rev(int l, int r) {
	ll ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += revseg[l++];
		if (r & 1) ret += revseg[--r];
	}
	return ret;
}