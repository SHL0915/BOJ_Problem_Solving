#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pair<pll, pll> L[2];

int func(pair<pll, pll> L1, pair<pll, pll> L2);
int CCW(pll A, pll B, pll C);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 2; i++) cin >> L[i].first.first >> L[i].first.second >> L[i].second.first >> L[i].second.second;
	cout << func(L[0], L[1]);
	return 0;
}

int func(pair<pll, pll> L1, pair<pll, pll> L2) {
	pll p1 = L1.first, p2 = L1.second, p3 = L2.first, p4 = L2.second;
	int ccw1 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int ccw2 = CCW(p3, p4, p1) * CCW(p3, p4, p2);
	if (ccw1 == 0 && ccw2 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return (p1 <= p4 && p3 <= p2);
	}
	else return (ccw1 <= 0 && ccw2 <= 0);
}

int CCW(pll A, pll B, pll C) {
	ll a = A.first * B.second + B.first * C.second + C.first * A.second;
	ll b = B.first * A.second + C.first * B.second + A.first * C.second;
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}