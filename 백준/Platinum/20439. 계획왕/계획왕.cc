#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
pii org[13];
int mark[1441];
int psum[1441];
int arr[13];
int table[1441][(1 << 13)];

int DP(int t, int state);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		org[i] = { a,b };
		for (int j = a; j <= b; j++) mark[j] = 1;		
	}
	for (int i = 1; i <= 1440; i++) psum[i] = psum[i - 1] + mark[i];

	for (int i = 0; i < K; i++) cin >> arr[i];

	memset(table, -1, sizeof(table));
	int ans = DP(0, 0);
	if (ans) cout << "GOOD";
	else cout << "BAD";
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

int DP(int t, int state) {
	if (t > 1440) return 0;
	if (state == (1 << K) - 1) return 1;
	int& ret = table[t][state];
	if (ret != -1) return ret;

	ret = 0;
	ret |= DP(t + 1, state);
	
	for (int i = 0; i < K; i++) {
		if (state & (1 << i)) continue;

		int cnt = 0;
		for (int j = 0; j < N; j++) {
			int s = org[j].first, e = org[j].second;
			if (s >= t + arr[i] || e <= t) cnt++;
		}

		if (cnt < N) continue;

		ret |= DP(t + arr[i], state | (1 << i));
	}


	return ret;
}