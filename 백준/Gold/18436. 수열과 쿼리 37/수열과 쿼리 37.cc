#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[100001];
ll seg[200005];

void update(int pos, int val);
int query(int l, int r);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] %= 2;
		if (arr[i] == 1) update(i, 1);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			c %= 2; 
			if (c == 0) update(b, 0);
			else update(b, 1);
		}
		else if (a == 2) cout << (c - b + 1) - query(b, c + 1) << '\n';
		else cout << query(b, c + 1) << '\n';
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

void update(int pos, int val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
	return;
}

int query(int l, int r) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += seg[l++];
		if (r & 1) ret += seg[--r];
	}
	return ret;
}