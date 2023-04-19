#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct millar_rabin {
	using ull = unsigned long long;
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
} millar_rabin;

string S, rvs;

void solve() {
	cin >> S;
	ll N = 0;
	for (int i = 0; i < S.length(); i++) {
		N *= 10;
		N += S[i] - '0';
		if (S[i] == '0' || S[i] == '1' || S[i] == '2' || S[i] == '5' || S[i] == '8') rvs = S[i] + rvs;
		else if (S[i] == '6') rvs = '9' + rvs;
		else if (S[i] == '9') rvs = '6' + rvs;
		else {
			cout << "no";
			return;
		}
	}

	ll rvs_N = 0;
	for (int i = 0; i < rvs.length(); i++) {
		rvs_N *= 10;
		rvs_N += rvs[i] - '0';
	}

	if (millar_rabin.IsPrime(N) && millar_rabin.IsPrime(rvs_N)) cout << "yes";
	else cout << "no";
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