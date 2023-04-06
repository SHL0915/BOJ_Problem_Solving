#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[10001];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	arr[N] = arr[0];
	double ans = 0;

	for (int i = 1; i <= N; i++) ans += (arr[i].first - arr[i - 1].first) * (arr[i].second + arr[i - 1].second);
	cout << abs(ans) / 2;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(1);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}