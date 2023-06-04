#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, D;
pii arr[50005];
ll seg[100005];
vector <ll> val;

void update(int pos, ll val);
ll query(int l, int r);

void solve() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		val.push_back(arr[i].first);
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for (int i = 0; i < N; i++) {
		ll now = arr[i].first, h = arr[i].second;
		int idx = lower_bound(val.begin(), val.end(), now) - val.begin() + 1;
		update(idx, h);
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		ll now = arr[i].first, h = arr[i].second;
		int idx = lower_bound(val.begin(), val.end(), now) - val.begin() + 1;
		int lidx = lower_bound(val.begin(), val.end(), now - D) - val.begin() + 1;
		int ridx = upper_bound(val.begin(), val.end(), now + D) - val.begin();

		ll lmax = query(lidx, idx), rmax = query(idx + 1, ridx + 1);

		if (lmax >= 2 * h && rmax >= 2 * h) cnt++;
	}

	cout << cnt;
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
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
	return;
}

ll query(int l, int r) {
	ll ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[l++]);
		if (r & 1) ret = max(ret, seg[--r]);
	}
	return ret;
}