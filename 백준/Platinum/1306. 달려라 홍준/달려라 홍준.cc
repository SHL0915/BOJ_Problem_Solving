#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[1000001];
int seg[2000005];

void update(int pos, int val);
int query(int l, int r);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	for (int i = M; i <= N - M + 1; i++) cout << query(i - (M - 1), i + M) << ' ';

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
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
	return;
}

int query(int l, int r) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
	}
	return ret;
}