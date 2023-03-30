#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <pii> seg;

void update(int pos, pii val);
pii query(int l, int r);

void solve() {
	cin >> N;
	seg.resize(2 * N + 5);
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		update(i, { a,i });
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		if (a == 1) {
			int pos, val;
			cin >> pos >> val;
			update(pos, { val, pos });
		}
		else {
			int l, r;
			cin >> l >> r;
			pii M = query(l, r + 1);
			update(M.second, { 0, M.second });
			cout << M.first + query(l, r + 1).first << '\n';
			update(M.second, M);
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

void update(int pos, pii val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
	return;
}

pii query(int l, int r) {
	pii ret = { 0,0 };
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
	}
	return ret;
}