#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[500001];
ll table[500001][2];
set <ll> ans;

ll GCD(ll a, ll b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		table[i][0] = arr[i];
		ans.insert(arr[i]);
	}

	int cnt = 1, sz = N;
	while (cnt++) {
		int ccnt = 0;
		for (int i = 0; i < sz - 1; i++) {
			ll now = GCD(table[i][cnt % 2], table[i + 1][cnt % 2]);
			if (ccnt == 0) table[ccnt][(cnt % 2) ^ 1] = now;
			else {
				if (now == table[ccnt - 1][(cnt % 2) ^ 1]) continue;
				else table[ccnt][(cnt % 2) ^ 1] = now;
			}
			ans.insert(now);
			ccnt++;
		}
		sz = ccnt;
		if (ccnt == 1) break;
	}

	cout << ans.size();
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

ll GCD(ll a, ll b) {
	if (a > b) {
		if (a % b) return GCD(a % b, b);
		else return b;
	}
	else {
		if (b % a) return GCD(b % a, a);
		else return a;
	}
}