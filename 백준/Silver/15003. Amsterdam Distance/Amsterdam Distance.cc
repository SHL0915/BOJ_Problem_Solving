#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<double, double>;

double M, N, R;
pii S, E;

void solve() {
	cin >> M >> N >> R;
	cin >> S.first >> S.second >> E.first >> E.second;

	double ans = 0x3f3f3f3f;
	for (int i = 0; i <= N; i++) {
		ans = min(ans, abs(S.second - i) / N * R + abs(E.second - i) / N * R + i / N * R * 3.141592653589 * abs(S.first - E.first) / M);
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
	cout << fixed;
	cout.precision(9);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}