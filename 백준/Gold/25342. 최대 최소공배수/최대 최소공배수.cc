#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

ll LCM(ll a, ll b);
ll GCD(ll a, ll b);

void solve() {
	cin >> N;
	if (N % 2) cout << LCM(LCM(N, N - 1), N - 2);
	else {
		ll ans = 0;
		ans = max(ans, LCM(LCM(N, N - 1), N - 3));
		ans = max(ans, LCM(LCM(N - 1, N - 2), N - 3));
		cout << ans;
	}
	cout << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

ll LCM(ll a, ll b) {
	return a * b / GCD(a, b);
}

ll GCD(ll a, ll b) {
	if (a > b) {
		if (a % b) return GCD(a % b, b);
		else return b;
	}
	else {
		if (b % a) return GCD(b % a, a);
		else return a;
	}
}