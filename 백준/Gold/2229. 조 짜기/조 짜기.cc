#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1001];
int table[1001];

int DP(int pos);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << DP(0);
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

int DP(int pos) {
	if (pos == N) return 0;
	int& ret = table[pos];
	if (ret != -1) return ret;
	ret = 0;

	int m = arr[pos], M = arr[pos];

	for (int i = pos; i < N; i++) {
		m = min(m, arr[i]);
		M = max(M, arr[i]);
		ret = max(ret, M - m + DP(i + 1));
	}

	return ret;
}