#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<double, double>;
double INF = 0x3f3f3f3f;

int N, R, BX, BY, BVX, BVY;
double X[50001], VX[50001], Y[50001], VY[50001];
vector <pair<double, int>> a;

double dist(double a, double b);
double sqrdist(double a, double b);
pii find_range(double a, double b, double c, double d);

void solve() {
	cin >> N >> R >> BX >> BY >> BVX >> BVY;
	for (int i = 0; i < N; i++) {

		cin >> X[i] >> Y[i] >> VX[i] >> VY[i];
		X[i] -= BX; VX[i] -= BVX;
		Y[i] -= BY; VY[i] -= BVY;
	}

	int plus = 0;

	for (int i = 0; i < N; i++) {
		if (VX[i] == 0 && VY[i] == 0) {
			if (sqrdist(X[i], Y[i]) <= R * R) plus++;
			continue;
		}

		pii range = find_range(X[i], VX[i], Y[i], VY[i]);
		if (range.first == INF && range.second == INF) continue;

		a.push_back({ max((double)0, range.first), 1 });
		a.push_back({ max((double)0, range.second), -1 });
	}
	sort(a.begin(), a.end());

	int ans = 0, cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		cnt += a[i].second;
		if (i == a.size() - 1 || a[i].first != a[i + 1].first) ans = max(ans, cnt);
	}

	cout << ans + plus;
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

double sqrdist(double a, double b) {
	return a * a + b * b;
}

pii find_range(double a, double b, double c, double d) {
	double aa = b * b + d * d;
	double bb = 2 * (a * b + c * d);
	double cc = a * a + c * c - R * R;

	if (bb * bb - 4 * aa * cc < 0) return { INF, INF };

	pii ret = { (-bb - sqrt(bb * bb - 4 * aa * cc)) / (2 * aa), (-bb + sqrt(bb * bb - 4 * aa * cc)) / (2 * aa) };

	return ret;
}