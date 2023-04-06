#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int G, N;
pair <ll, pii> arr[100001];
ll t[100001];
pair <ll, pii> cow[100001];

ll sqrdist(pii a, pii b);

void solve() {
	cin >> G >> N;
	for (int i = 0; i < G; i++) cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
	for (int i = 0; i < N; i++) cin >> cow[i].second.first >> cow[i].second.second >> cow[i].first;
	sort(arr, arr + G);
	for (int i = 0; i < G; i++) t[i] = arr[i].first;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(t, t + G, cow[i].first) - t;

		int flag = 0;
		if (idx != G) {
			if (sqrdist(cow[i].second, arr[idx].second) > abs(cow[i].first - t[idx]) * abs(cow[i].first - t[idx])) flag = 1;
		}
		if (idx != 0) {
			if (sqrdist(cow[i].second, arr[idx - 1].second) > abs(cow[i].first - t[idx - 1]) * abs(cow[i].first - t[idx - 1])) flag = 1;
		}

		ans += flag;
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

ll sqrdist(pii a, pii b) {
	ll dx = a.first - b.first, dy = a.second - b.second;
	return dx * dx + dy * dy;
}