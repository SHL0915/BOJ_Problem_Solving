#include <bits/stdc++.h>
using namespace std;

int X, Y, D, T, cnt;
double ans;

long long sqrdist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(15);
	cin >> X >> Y >> D >> T;
	long long d = sqrdist(0, 0, X, Y);
	double dist = sqrt(d);
	double temp = dist;
	while (dist >= (double)0) {
		dist -= D;
		ans += T;
		cnt++;
	}
	dist += D;
	ans -= T;
	if (dist > (double)0) {
		if (cnt > 1) ans += min(dist, (double)T);
		else ans += min({ dist, (double)(T + (D - dist)), (double)(T + T) });
	}
	cout << min(temp, ans);
	return 0;
}