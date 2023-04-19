#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

struct MillerRabin {
	ll Mul(ll x, ll y, ll MOD) {
		ll ret = x * y - MOD * ull(1.L / MOD * x * y);
		return ret + MOD * (ret < 0) - MOD * (ret >= (ll)MOD);
	}
	ll _pow(ll x, ll n, ll MOD) {
		ll ret = 1; x %= MOD;
		for (; n; n >>= 1) {
			if (n & 1) ret = Mul(ret, x, MOD);
			x = Mul(x, x, MOD);
		}
		return ret;
	}
	bool Check(ll x, ll p) {
		if (x % p == 0) return 0;
		for (ll d = x - 1; ; d >>= 1) {
			ll t = _pow(p, d, x);
			if (d & 1) return t != 1 && t != x - 1;
			if (t == x - 1) return 0;
		}
	}
	bool IsPrime(ll x) {
		if (x == 2 || x == 3 || x == 5 || x == 7) return 1;
		if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return 0;
		if (x < 121) return x > 1;
		if (x < 1ULL << 32) for (auto& i : { 2, 7, 61 }) {
			if (x == i) return 1;
			if (x > i && Check(x, i)) return 0;
		}
		else for (auto& i : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
			if (x == i) return 1;
			if (x > i && Check(x, i)) return 0;
		}
		return 1;
	}
};

struct PollardRho : public MillerRabin {
	void Rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		if (~n & 1) { v.push_back(2); Rec(n >> 1, v); return; }
		if (IsPrime(n)) { v.push_back(n); return; }
		ll a, b, c, g = n;
		auto f = [&](ll x) { return (c + Mul(x, x, n)) % n; };
		do {
			if (g == n) {
				a = b = rand() + 2;
				c = rand() + 1;
			}
			a = f(a); b = f(f(b)); g = gcd(abs(a - b), n);
		} while (g == 1);
		Rec(g, v); Rec(n / g, v);
	}
	vector<ll> Factorize(ll n) {
		vector<ll> ret; Rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
} P;

ll N;

void solve() {
	cin >> N;
	vector <ll> ans = P.Factorize(N);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
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