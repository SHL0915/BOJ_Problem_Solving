#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K;
int arr[1000001];
int cnt[1000001][2];
int table[1000001][2];

int DP(int pos, int parity);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] %= 2;
		cnt[i % K][arr[i]]++;
	}
	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
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

int DP(int pos, int parity) {
	if (pos == K) {
		if (parity == 0) return 0;
		else return INF;
	}
	int& ret = table[pos][parity];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, cnt[pos][1] + DP(pos + 1, parity));
	ret = min(ret, cnt[pos][0] + DP(pos + 1, parity ^ 1));
	return ret;
}