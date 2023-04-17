#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
ll S, A;
double a;
pii arr[205];

void solve() {
	cin >> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		arr[i + N] = { arr[i].first, arr[i].second };
	}

	for (int i = 0; i < N; i++) A += (arr[i + 1].first - arr[i].first) * (arr[i + 1].second + arr[i].second);
	A = abs(A);

	for (int i = 0; i < N; i++) {
		ll s = 0;
		for (int j = i; j < i + 2; j++) s += (arr[j + 1].first - arr[j].first) * (arr[j + 1].second + arr[j].second);
		s += (arr[i].first - arr[i + 2].first) * (arr[i].second + arr[i + 2].second);
		S += abs(s);
	}

	double l = 2, r = 1000;

	for (int i = 0; i < 10000000; i++) {
		double mid = (l + r) / 2;

		if (S <= A * mid * mid * (1 - a)) r = mid;
		else l = mid;
	}	

	cout << (l + r) / 2;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}