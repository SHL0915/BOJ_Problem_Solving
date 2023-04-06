#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[55];

void solve() {
	cin >> N;
	double ans = 0;
	for (int i = 0; i < N; i++) {
		int P; cin >> P;
		for (int j = 0; j < P; j++) cin >> arr[j].first >> arr[j].second;
		arr[P] = arr[0];
		double result = 0;
		for (int j = 0; j < P; j++) result += (arr[j + 1].first - arr[j].first) * (arr[j + 1].second + arr[j].second);
		ans += abs(result) / 2;
	}

	cout << (ll)floor(ans);
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