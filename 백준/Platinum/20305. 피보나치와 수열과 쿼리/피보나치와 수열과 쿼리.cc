#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1000000007;

int N, Q;
int fibo[1000005];
int ans[1000005];

void solve() {
	cin >> N >> Q;
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		ans[l]++;
		if (ans[l] >= mod) ans[l] -= mod;

		ans[r + 1] -= fibo[r - l + 2];
		if (ans[r + 1] < 0) ans[r + 1] += mod;
		else if (ans[r + 1] >= mod) ans[r + 1] -= mod;

		ans[r + 2] -= fibo[r - l + 1];
		if (ans[r + 2] < 0) ans[r + 2] += mod;
		else if (ans[r + 2] >= mod) ans[r + 2] -= mod;
	}

	for (int i = 2; i <= N; i++) {
		ans[i] += ans[i - 1];
		if (ans[i] >= mod) ans[i] -= mod;
		ans[i] += ans[i - 2];
		if (ans[i] >= mod) ans[i] -= mod;
	}

	for (int i = 1; i <= N; i++) cout << ans[i] << " ";
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	fibo[0] = 0; fibo[1] = 1;
	for (int i = 2; i < 1000005; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]);
		if (fibo[i] >= mod) fibo[i] -= mod;
	}
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}