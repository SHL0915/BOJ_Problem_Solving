#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector <ll> seg;

void update(int pos, ll val);
ll query(int l, int r);

void solve() {
	cin >> N >> M >> K;
	seg.clear(); seg.resize(2 * M + 5);

	ll ans = 0;

	vector <pii> arr;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < K; i++) {
		int a = arr[i].first, b = arr[i].second;
		ans += query(b + 1, M + 1);
		update(b, 1);
	}

	cout << ans << '\n';
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
	int tc = 1;
	while (t--) {
		cout << "Test case " << tc << ": ";
		solve();
		tc++;
	}
	return 0;
}

void update(int pos, ll val) {
	for (seg[pos += M] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
	return;
}

ll query(int l, int r) {
	ll ret = 0;
	for (l += M, r += M; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += seg[l++];
		if (r & 1) ret += seg[--r];
	}

	return ret;
}