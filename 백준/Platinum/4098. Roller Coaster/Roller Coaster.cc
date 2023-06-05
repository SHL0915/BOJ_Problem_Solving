#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K, L;
pii arr[1005];
int table[20005];

void solve() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].first;
	}

	int ans = 0;

	memset(table, INF, sizeof(table));
	table[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = sum; j >= 0; j--) {
			if (table[j] == INF) continue;
			if (table[j] + arr[i].second <= L) table[j + arr[i].first] = min(table[j + arr[i].first], table[j] + arr[i].second);
			table[j] = max(0, table[j] - K);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (table[i] != INF) ans = max(ans, i);
	}

	cout << ans << '\n';
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
	while (1) {
		cin >> N >> K >> L;
		if (N == 0 && K == 0 && L == 0) break;
		solve();
	}
	return 0;
}