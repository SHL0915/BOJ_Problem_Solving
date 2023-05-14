#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, D, S;

void solve() {
	cin >> N >> K >> D >> S;

	ll tot = N * D;
	ll solved = S * K;

	double ans = (double)(tot - solved) / (N - K);

	if (ans < 0 || ans > 100) cout << "impossible";
	else cout << ans;

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(9);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}