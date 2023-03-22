#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
ll seg[600005];

void update(int pos, ll val);
ll query(int l, int r);

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		ll a; cin >> a;
		if (i % 2) update(i, a);
		else update(i, -a);
	}

	for (int i = 0; i < Q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) cout << abs(query(b, c + 1)) << '\n';
		else {
			if (b % 2) update(b, c);
			else update(b, -c);
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

void update(int pos, ll val) {
	for (seg[pos += N] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
	return;
}

ll query(int l, int r) {
	ll ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += seg[l++];
		if (r & 1) ret += seg[--r];
	}
	return ret;
}