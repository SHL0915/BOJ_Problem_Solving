#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

pii arr[12];

void solve() {
	for (int i = 0; i < 11; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + 11);

	int tot = 0, ans = 0;

	for (int i = 0; i < 11; i++) {
		tot += arr[i].first;
		ans += tot + arr[i].second * 20;
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