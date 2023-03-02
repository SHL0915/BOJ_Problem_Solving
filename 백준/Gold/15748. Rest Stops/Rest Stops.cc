#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll L, N, Rf, Rb;
pii arr[100001];

bool cmp(pii a, pii b);

void solve() {
	cin >> L >> N >> Rf >> Rb;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + N, cmp);

	ll now = 0, ans = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i].first < now) continue;
		ll dist = arr[i].first - now;
		ll t = (Rf - Rb) * dist;
		ans += arr[i].second * t;
		now = arr[i].first;
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

bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}