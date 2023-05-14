#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];
ll psum[100005];
ll suffix_min[100005];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	suffix_min[N] = arr[N];
	for (int i = N - 1; i >= 1; i--) suffix_min[i] = min(arr[i], suffix_min[i + 1]);
	
	double ans = 0;

	for (int i = 2; i <= N - 1; i++) {
		double now = (double)(psum[N] - psum[i - 1] - suffix_min[i]) / (N - i);
		ans = max(ans, now);
	}

	for (int i = 2; i <= N - 1; i++) {
		double now = (double)(psum[N] - psum[i - 1] - suffix_min[i]) / (N - i);
		if (now == ans) cout << i - 1 << '\n';
	}

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