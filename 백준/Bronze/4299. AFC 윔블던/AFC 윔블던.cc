#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B;

void solve() {
	cin >> A >> B;
	int sum = A + B;
	if (sum % 2) {
		cout << -1;
		return;
	}

	int ans_a = sum / 2;
	int ans_b = A - ans_a;

	if (ans_a < 0 || ans_b < 0) cout << -1;
	else cout << ans_a << " " << ans_b;

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