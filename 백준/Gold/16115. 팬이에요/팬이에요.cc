#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const double PI = 3.1415926535897932384626;

int N;
pii arr[300005];

void solve() {
	cin >> N;
	ll max_sqr = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		max_sqr = max(max_sqr, arr[i].first * arr[i].first + arr[i].second * arr[i].second);
	}

	vector <pii> dots;
	for (int i = 0; i < N; i++) {
		if (arr[i].first * arr[i].first + arr[i].second * arr[i].second == max_sqr) dots.push_back(arr[i]);
	}

	vector <double> angle;
	for (int i = 0; i < dots.size(); i++) {
		pair<double, double> now = dots[i];
		double res = atan2(now.second, now.first) * 180.0 / PI;
		if (res < 0) res += 360.0;
		angle.push_back(res);
	}

	sort(angle.begin(), angle.end());

	double ans = 0;
	for (int i = 0; i < angle.size() - 1; i++) {
		double now = angle[i + 1] - angle[i];
		ans = max(ans, now);
	}
	ans = max(ans, angle[0] + 360.0 - angle[angle.size() - 1]);

	cout << ans;
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