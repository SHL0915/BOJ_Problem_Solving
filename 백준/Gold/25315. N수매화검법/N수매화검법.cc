#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, ans;
pair<ll, pair<pii, pii>> arr[2501];

ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);
bool check(pair<pii, pii> a, pair<pii, pii> b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].second.first.first >> arr[i].second.first.second >> arr[i].second.second.first >> arr[i].second.second.second >> arr[i].first;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		ll cnt = 1;
		for (int j = i + 1; j < N; j++) {
			if (check(arr[i].second, arr[j].second)) cnt++;
		}
		ans += cnt * arr[i].first;
	}
	cout << ans;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

ll CCW(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first , a.second - b.second };
}

bool check(pair<pii, pii> a, pair<pii, pii> b) {
	ll ccw1 = CCW(a.first, a.second, b.first) * CCW(a.first, a.second, b.second);
	ll ccw2 = CCW(b.first, b.second, a.first) * CCW(b.first, b.second, a.second);
	if (ccw1 < 0 && ccw2 < 0) return true;
	else return false;
}