#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int C, M;
int arr[101][101];
int table[101][101];

int DP(int now, int left);

void solve() {
	cin >> C >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= C; j++) cin >> arr[i][j];
	}

	memset(table, -1, sizeof(table));
	cout << DP(0, C);
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

int DP(int now, int left) {
	if (now == M || left == 0) return 0;
	int& ret = table[now][left];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i <= left; i++) ret = max(ret, arr[now][i] + DP(now + 1, left - i));

	return ret;
}