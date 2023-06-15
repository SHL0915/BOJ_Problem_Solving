#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];
ll psum[100005];

pair<ll, pii> DNC(int l, int r);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	pair <ll, pii> ans = DNC(1, N);
	cout << ans.first << '\n' << ans.second.first << " " << ans.second.second;
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

pair<ll, pii> DNC(int l, int r) {
	if (l == r) return { arr[l] * arr[l], {l,l} };
	int mid = (l + r) / 2;
	pair<ll, pii> lval = DNC(l, mid);
	pair<ll, pii> rval = DNC(mid + 1, r);
	pair<ll, pii> ret = max(lval, rval);

	ll lidx = mid, ridx = mid, m = arr[mid];
	ret = max(ret, { m * (psum[ridx] - psum[lidx - 1]) , {lidx, ridx} });

	while (lidx > l || ridx < r) {
		if (lidx == l) ridx++;
		else if (ridx == r) lidx--;
		else {
			if (arr[lidx - 1] > arr[ridx + 1]) lidx--;
			else ridx++;
		}
		m = min({ m, arr[lidx], arr[ridx] });
		ret = max(ret, { m * (psum[ridx] - psum[lidx - 1]) , {lidx, ridx} });
	}

	return ret;
}