#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

ll N, K, Q;
ll fact[4000001];
ll inv[4000001];

ll inverse(ll a);

void solve() {
	cin >> Q;
	
	fact[0] = 1;
	for (int i = 1; i <= 4000000; i++) fact[i] = (fact[i - 1] * i) % mod;

	inv[4000000] = inverse(fact[4000000]);
	for (int i = 3999999; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % mod;

	for (int i = 0; i < Q; i++) {
		cin >> N >> K;
		cout << ((fact[N] * inv[N - K]) % mod * inv[K]) % mod << '\n';
	}

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

ll inverse(ll a) {
	ll bit = 1, ret = 1;
	while (bit <= mod - 2) {
		if (bit & (mod - 2)) ret = (ret * a) % mod;
		bit <<= 1;
		a = (a * a) % mod;
	}
	ret %= mod;
	return ret;
}