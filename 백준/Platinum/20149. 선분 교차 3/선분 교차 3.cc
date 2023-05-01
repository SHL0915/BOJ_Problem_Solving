#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

pair<pii, pii> L1, L2;

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
void find_inter(pii a, pii b, pii c, pii d);

void solve() {
	cin >> L1.first.first >> L1.first.second >> L1.second.first >> L1.second.second;
	cin >> L2.first.first >> L2.first.second >> L2.second.first >> L2.second.second;

	ll ccw1 = ccw(L1.first, L1.second, L2.first) * ccw(L1.first, L1.second, L2.second);
	ll ccw2 = ccw(L2.first, L2.second, L1.first) * ccw(L2.first, L2.second, L1.second);

	if (ccw1 == 0 && ccw2 == 0) {
		if (L1.first > L1.second) swap(L1.first, L1.second);
		if (L2.first > L2.second) swap(L2.first, L2.second);
		if (L1.first <= L2.second && L1.second >= L2.first) {
			cout << 1 << '\n';
			find_inter(L1.first, L1.second, L2.first, L2.second);
		}
		else cout << 0 << '\n';
	}
	else if (ccw1 <= 0 && ccw2 <= 0) {
		cout << 1 << '\n';
		find_inter(L1.first, L1.second, L2.first, L2.second);
	}
	else cout << 0 << '\n';

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(15);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

ll ccw(pii a, pii b, pii c) {
	pii u = sub(a, b);
	pii v = sub(c, b);
	ll ret = u.first * v.second - v.first * u.second;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}


void find_inter(pii a, pii b, pii c, pii d) {
	double px = (a.first * b.second - a.second * b.first) * (c.first - d.first) - (a.first - b.first) * (c.first * d.second - c.second * d.first);
	double py = (a.first * b.second - a.second * b.first) * (c.second - d.second) - (a.second - b.second) * (c.first * d.second - c.second * d.first);
	double p = (a.first - b.first) * (c.second - d.second) - (a.second - b.second) * (c.first - d.first);

	if (p == 0) {
		if (b == c && a <= c) cout << b.first << " " << b.second << '\n';
		else if (a == d && c <= a) cout << a.first << " " << a.second << '\n';
	}
	else {
		double x = px / p;
		double y = py / p;
		cout << x << " " << y << '\n';
	}

	return;
}