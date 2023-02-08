#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K;
int tree[18][18];
int arr[18];
int table[18][(1 << 18)][18];

int DP(int now, int state, int k);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a][b] = 1;
		tree[b][a] = 1;
	}
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(table, -1, sizeof(table));
	cout << arr[0] + DP(0, 1, 1);
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

int DP(int now, int state, int k) {
	if (k == K) return 0;
	int& ret = table[now][state][k];
	if (ret != -1) return ret;
	ret = -INF;
	for (int i = 0; i < N; i++) {
		if (tree[now][i] == 0) continue;
		if (state & (1 << i)) ret = max(ret, DP(i, state, k));
		else ret = max(ret, arr[i] + DP(i, state | (1 << i), k + 1));
	}
	return ret;
}