#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[2005];
ll org[2005];

void solve() {
	cin >> N;

	ll M = 0;

	for (int i = 0; i < N; i++) {
		cin >> org[i];
		org[i + N] = org[i];
	}

	ll ans = 0;

	for (int k = N; k < 2 * N; k++) {
		ll cnt = 0, ff = 0;
		for (int i = 0; i < 2 * N; i++) arr[i] = org[i];
		for (int i = k; i > k - N; i--) {
			if (arr[i] == 0) {
				int flag = 0;
				for (int j = i; j > k - N; j--) {
					if (arr[j] != 0) {
						cnt += (i - j) * (i - j);
						arr[i]++;
						arr[j]--;
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ff = 1;
					break;
				}
			}
			else continue;
		}
		if (ff) continue;
		ans = cnt;
	}


	cout << ans;
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