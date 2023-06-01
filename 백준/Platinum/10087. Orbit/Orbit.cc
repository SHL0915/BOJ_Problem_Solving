#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<double, double>;

ll N, R;
pair<pii, ll> arr[100005];

double F(ll L, pii a, pii b);
pair <double, double> find_pair(double x);

void solve() {
	cin >> N >> R;
	for (int i = 0; i < N; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;

	double a = 0, b = 0;
	for (int i = 0; i < N; i++) a = max(a, F(arr[i].second, arr[i].first, make_pair(-R, 0)));
	for (int i = 0; i < N; i++) b = max(b, F(arr[i].second, arr[i].first, make_pair(R, 0)));

	if (a == b) {
		cout << -R << " " << 0 << " " << R << " " << 0;
		return;
	}

	double l = -R, r = R;

	while (r - l > 2e-7) {
		double mid = (l + r) / 2;
		pair <double, double> now = find_pair(mid);
		pair <double, double> op = { -now.first, -now.second };

		if (a > b) {
			double val = 0;
			for (int i = 0; i < N; i++) val = max(val, F(arr[i].second, arr[i].first, now));
			double opposite = 0;
			for (int i = 0; i < N; i++) opposite = max(opposite, F(arr[i].second, arr[i].first, op));

			if (val >= opposite) l = mid;
			else r = mid;
		}
		else {
			double val = 0;
			for (int i = 0; i < N; i++) val = max(val, F(arr[i].second, arr[i].first, now));
			double opposite = 0;
			for (int i = 0; i < N; i++) opposite = max(opposite, F(arr[i].second, arr[i].first, op));

			if (val <= opposite) l = mid;
			else r = mid;
		}
	}

	pair <double, double> ans = find_pair((l + r) / 2);

	cout << ans.first << " " << ans.second << " " << -ans.first << " " << -ans.second;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(9);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

double F(ll L, pii a, pii b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	double ret = L;
	ret /= (dx * dx + dy * dy);
	return ret;
}

pair <double, double> find_pair(double x) {
	double y = R * R - x * x;
	y = sqrt(y);

	return { x,y };
}