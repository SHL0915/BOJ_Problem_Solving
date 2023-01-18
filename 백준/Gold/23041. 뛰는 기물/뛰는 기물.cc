#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M;

ll GCD(ll a, ll b);

void solve() {
	cin >> N >> M;
	if (N == 0) {
		cout << M * M;
		return;
	}
	else if (M == 0) {
		cout << N * N;
		return;
	}
	ll gcd = GCD(N, M);
	N /= gcd;
	M /= gcd;
	ll ans;
	if ((N + M) % 2) ans = 1;
	else ans = 2;
	cout << ans * gcd * gcd;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

ll GCD(ll a, ll b) {
	if (a > b) {
		if (a % b) return GCD(a % b, b);
		else return b;
	}
	else {
		if (b % a) return GCD(b % a, a);
		return a;
	}
}