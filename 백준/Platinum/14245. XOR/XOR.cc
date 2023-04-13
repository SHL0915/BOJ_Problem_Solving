#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <ll> seg, lazy;

void update(int node, int start, int end, int left, int right, ll val);
void update_lazy(int node, int start, int end);
ll query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	seg.resize(4 * N);
	lazy.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		ll a; cin >> a;
		update(1, 1, N, i, i, a);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c, d;
			cin >> b >> c >> d;
			update(1, 1, N, b + 1, c + 1, d);
		}
		else {
			int b; cin >> b;
			cout << query(1, 1, N, b + 1, b + 1) << '\n';
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
	//cin >> t;
	while (t--) solve();
	return 0;
}

void update(int node, int start, int end, int left, int right, ll val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] ^= val;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		if ((start + end - 1) % 2) seg[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
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
	return query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right);
}