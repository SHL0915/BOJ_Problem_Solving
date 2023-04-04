#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, tC, tM;
pair<pii, ll> arr[101];

int check(ll k);

void solve() {
	cin >> N >> tC >> tM;
	for (int i = 0; i < N; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;

	ll l = 0, r = tC + tM - 2;

	while (l < r) {
		ll mid = (l + r) / 2;		
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << '\n';
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
	while (t--) solve();
	return 0;
}

int check(ll k) {
	double lx = max(1LL, tC - k), hx = min(tC, tC + tM - 1 - k);

	for (int i = 0; i < N; i++) {
		ll a = arr[i].first.first, b = arr[i].first.second, c = arr[i].second, d = tC + tM - k;
		ll fr = a - b, ba = c - b * d;
		if (a - b > 0) hx = min(hx, (double)ba / fr);
		else if (a - b == 0) {
			if (ba < 0) return 0;
		}
		else lx = max(lx, (double)ba / fr);
	}

	if (lx > hx) return 0;
	else {
		int flag = 0;
		for (ll i = lx; i <= hx; i++) {
			if (i >= lx && i <= hx) return 1;
		}
		return 0;
	}
}