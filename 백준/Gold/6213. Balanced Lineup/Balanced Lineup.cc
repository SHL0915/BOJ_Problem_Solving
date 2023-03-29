#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, Q;
vector <int> min_seg, max_seg;

void update_min(int pos, int val);
void update_max(int pos, int val);
int query_min(int l, int r);
int query_max(int l, int r);

void solve() {
	cin >> N >> Q;

	min_seg.resize(4 * N, INF);
	max_seg.resize(4 * N);

	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		update_min(i, a);
		update_max(i, a);
	}

	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		r++;
		cout << query_max(l, r) - query_min(l, r) << '\n';
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

void update_min(int pos, int val) {
	for (min_seg[pos += N] = val; pos > 0; pos >>= 1) min_seg[pos >> 1] = min(min_seg[pos], min_seg[pos ^ 1]);
	return;
}

void update_max(int pos, int val) {
	for (max_seg[pos += N] = val; pos > 0; pos >>= 1) max_seg[pos >> 1] = max(max_seg[pos], max_seg[pos ^ 1]);
	return;
}

int query_min(int l, int r) {
	int ret = INF;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = min(ret, min_seg[l++]);
		if (r & 1) ret = min(ret, min_seg[--r]);
	}
	return ret;
}

int query_max(int l, int r) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, max_seg[l++]);
		if (r & 1) ret = max(ret, max_seg[--r]);
	}
	return ret;
}