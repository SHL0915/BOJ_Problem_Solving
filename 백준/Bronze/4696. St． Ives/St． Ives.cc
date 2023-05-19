#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

double A;

void solve() {
	while (1) {
		cin >> A;
		if (A == 0) break;

		double sum = 1;
		sum += A;
		sum += A * A;
		sum += A * A * A;
		sum += A * A * A * A;

		cout << sum << '\n';
	}
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}