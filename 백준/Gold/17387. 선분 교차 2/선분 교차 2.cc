#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

pii A, B, C, D;

ll CCW(pii a, pii b, pii c);
pii sub(pii a, pii b);

void solve() {
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;
	cin >> D.first >> D.second;
	int ccw1 = CCW(A, B, C) * CCW(A, B, D);
	int ccw2 = CCW(C, D, A) * CCW(C, D, B);
	if (ccw1 == 0 && ccw2 == 0) {
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		if (A <= D && C <= B) cout << 1;
		else cout << 0;
	}
	else if (ccw1 <= 0 && ccw2 <= 0) cout << 1;
	else cout << 0;
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

ll CCW(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}