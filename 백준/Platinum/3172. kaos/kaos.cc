#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string arr[100001];
map <string, int> idx;
ll seg[200005];

void update(int pos, ll val);
ll query(int l, int r);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		string s = "";
		for (int j = 0; j < arr[i].length(); j++) s = arr[i][j] + s;
		arr[i] = s;
		idx[arr[i]] = i + 1;
	}
	sort(arr, arr + N, greater<>());

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += query(1, idx[arr[i]] + 1);
		update(idx[arr[i]], 1);
	}

	cout << ans;
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