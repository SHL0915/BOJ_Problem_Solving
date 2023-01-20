#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll absol(ll a);
ll GCD(ll a, ll b);
pii EEu(ll a, ll b);
tuple<ll, ll, ll> eeu(ll a, ll b) {
	if (b == 0LL) return { a, 1LL, 0LL };
	ll g, x, y;
	tie(g, x, y) = eeu(b, a % b);
	return { g,y,x - a / b * y };
}

void solve() {
	ll A, B, C, x1, x2, y1, y2;
	cin >> A >> B >> C >> x1 >> x2 >> y1 >> y2;
	ll g, x0, y0;
	tie(g, x0, y0) = eeu(A, B);
	if (x1 > x2 || y1 > y2) {
		cout << 0;
		return;
	}
	if (A == 0 && B == 0) {
		if (C == 0) cout << (x2 - x1 + 1) * (y2 - y1 + 1);
		else cout << 0;
		return;
	}
	if (A == 0) {
		if (C % B) cout << 0;
		else {
			if (-C / B >= y1 && -C / B <= y2) cout << x2 - x1 + 1;
			else cout << 0;
		}
		return;
	}
	if (B == 0) {
		if (C % A) cout << 0;
		else {
			if (-C / A >= x1 && -C / A <= x2) cout << y2 - y1 + 1;
			else cout << 0;
		}
		return;
	}
	if (C % g) {
		cout << 0;
		return;
	}	
	x0 *= -C / g;
	y0 *= -C / g;
	ll lx, rx, ly, ry;
	if (B / g < 0) {
		lx = ceil((double)(x2 - x0) * g / B);
		rx = floor((double)(x1 - x0) * g / B);
	}
	else {
		lx = ceil((double)(x1 - x0) * g / B);
		rx = floor((double)(x2 - x0) * g / B);
	}
	if (A / g < 0) {
		ly = ceil((double)(y0 - y1) * g / A);
		ry = floor((double)(y0 - y2) * g / A);
	}
	else {
		ly = ceil((double)(y0 - y2) * g / A);
		ry = floor((double)(y0 - y1) * g / A);
	}	
	ll l = max(lx, ly), r = min(rx, ry);
	if (l > r) cout << 0;
	else cout << r - l + 1;
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

ll absol(ll a) {
	if (a < 0) return -a;
	else return a;
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

pii EEu(ll a, ll b) {
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
	return { s1, t1 };
}