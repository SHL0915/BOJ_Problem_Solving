#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

tuple<ll, ll, ll> EEu(ll a, ll b) {
	if (b == 0) return { a, 1, 0 };
	ll g, x, y;
	tie(g, x, y) = EEu(b, a % b);
	return { g,y,x - a / b * y };
}

void solve() {
	ll A, B, C, x1, x2, y1, y2;
	cin >> A >> B >> C >> x1 >> x2 >> y1 >> y2;
	ll g, x0, y0;
	tie(g, x0, y0) = EEu(A, B);
	x0 *= -C / g;
	y0 *= -C / g;
	if (x1 > x2 || y1 > y2) cout << 0;
	else if (A == 0 && B == 0) {
		if (C == 0) cout << (x2 - x1 + 1) * (y2 - y1 + 1);
		else cout << 0;
	}
	else if (A == 0) {
		if (C % B) cout << 0;
		else {
			if (-C / B >= y1 && -C / B <= y2) cout << x2 - x1 + 1;
			else cout << 0;
		}
	}
	else if (B == 0) {
		if (C % A) cout << 0;
		else {
			if (-C / A >= x1 && -C / A <= x2) cout << y2 - y1 + 1;
			else cout << 0;
		}
	}
	else if (C % g) cout << 0;
	else {
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
	}
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