#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1000000000;

ll t, K, C;

ll GCD(ll a, ll b);
ll EEu(ll a, ll b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> K >> C;
		if (GCD(K, C) != 1) cout << "IMPOSSIBLE\n";
		else {
			ll ans = (EEu(C, K) + K) % K;
			while (ans * C <= K) ans += K;
			if (ans > INF) cout << "IMPOSSIBLE\n";
			else cout << ans << '\n';
		}
	}
	return 0;
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

ll EEu(ll a, ll b) {
	ll s0 = 1, s1 = 0, t0 = 0, t1 = 1, r0 = a, r1 = b, q;
	while (1) {
		q = r0 / r1;
		r0 %= r1; swap(r0, r1);
		if (r1 == 0) break;
		s0 -= q * s1; swap(s0, s1);
		t0 -= q * t1; swap(t0, t1);
		s0 %= b;
		t0 %= a;
	}
	return s1;
}