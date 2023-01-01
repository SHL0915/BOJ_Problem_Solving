#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll p[4];

ll CCW(pll A, pll B, pll C);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> p[i].first >> p[i].second;
	ll ccw134 = CCW(p[0], p[1], p[2]) * CCW(p[0], p[1], p[3]);
	ll ccw312 = CCW(p[2], p[3], p[0]) * CCW(p[2], p[3], p[1]);
	if (ccw134 <= 0 && ccw312 <= 0) cout << 1;
	else cout << 0;
	return 0;
}

ll CCW(pll A, pll B, pll C) {
	ll a = A.first * B.second + B.first * C.second + C.first * A.second;
	ll b = B.first * A.second + C.first * B.second + A.first * C.second;
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}