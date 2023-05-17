#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

pii A, B, C, D;
pii arr[4];

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int line_intersect(pii a, pii b, pii c, pii d);
int in_rec(pii a);

void solve() {
	cin >> A.first >> A.second >> B.first >> B.second;
	cin >> C.first >> C.second >> D.first >> D.second;

	arr[0] = { min(C.first,D.first), min(C.second,D.second) };
	arr[1] = { max(C.first,D.first), min(C.second,D.second) };
	arr[2] = { max(C.first,D.first), max(C.second,D.second) };
	arr[3] = { min(C.first,D.first), max(C.second,D.second) };

	int flag = 0;
	for (int i = 0; i < 4; i++) flag |= line_intersect(A, B, arr[i], arr[(i + 1) % 4]);
	
	if (A.first >= arr[0].first && A.first <= arr[1].first && A.second >= arr[0].second && A.second <= arr[2].second) flag = 1;

	if (flag) cout << "T\n";
	else cout << "F\n";

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

int line_intersect(pii a, pii b, pii c, pii d) {
	ll ccw1 = ccw(a, b, c) * ccw(a, b, d);
	ll ccw2 = ccw(c, d, a) * ccw(c, d, b);
	if (ccw1 == 0 && ccw2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && b >= c) return 1;
		else return 0;
	}
	else if (ccw1 <= 0 && ccw2 <= 0) return 1;
	else return 0;
}

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}

int in_rec(pii a) {
	int now = -1;

	for (int i = 0; i < 4; i++) {
		ll res = ccw(arr[i], arr[(i + 1) % 4], a);
		if (now == -1) now = res;
		else {
			if (now != res) return 0;
		}
	}

	return 1;
}