#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[100005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, [&](pii a, pii b) {
		return a.second < b.second;
		});

	ll ans = 0;

	int lptr = 0, rptr = N - 1;
	while (1) {
		if (arr[lptr].first == 0) lptr++;
		if (arr[rptr].first == 0) rptr--;
		if (lptr > rptr) break;
		if (lptr == rptr) {
			ans = max(ans, arr[lptr].second * 2);
			break;
		}
		int amount = min(arr[lptr].first, arr[rptr].first);
		ans = max(ans, arr[lptr].second + arr[rptr].second);
		arr[lptr].first -= amount;
		arr[rptr].first -= amount;
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