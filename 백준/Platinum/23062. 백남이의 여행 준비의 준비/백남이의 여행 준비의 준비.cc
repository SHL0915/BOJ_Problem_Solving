#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int flag = 0;

ll GCD(ll a, ll b);
ll LCM(ll a, ll b);
ll EEu(ll a, ll b);
pii CRT(pii a, pii b);

void solve() {
	flag = 0;
	ll A, B, C, a, b, c;
	cin >> A >> B >> C >> a >> b >> c;
	ll g = GCD(A, B);	
	pii ans = CRT({ a,A }, { b,B });
	ans = CRT(ans, { c,C });
	if (flag) cout << -1 << '\n';
	else cout << (ans.first + ans.second) % ans.second << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
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
		else return a;
	}
}

ll LCM(ll a, ll b) {
	return a / GCD(a, b) * b;
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

pii CRT(pii a, pii b) {
	ll r1 = a.first, r2 = b.first, d1 = a.second, d2 = b.second;
	ll g = GCD(d1, d2), d = LCM(d1, d2), r;	
	if ((r2 - r1) % g) {
		flag = 1;
		return { -1 ,-1 };
	}
	ll x1 = EEu(d1, d2);
	x1 *= (r2 - r1) / g;
	x1 %= d2 / g;
	r = d1 * x1 + r1;
	return { r, d };
}