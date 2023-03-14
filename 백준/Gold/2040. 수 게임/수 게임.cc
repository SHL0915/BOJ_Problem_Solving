#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[3001];
int psum[3001];
int table[3001][2];

int DP(int pos, int turn);

void solve() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	memset(table, INF, sizeof(table));
	int ans = DP(N, 0);

	if (2 * ans < psum[N]) cout << "A";
	else if (2 * ans == psum[N]) cout << "D";
	else cout << "B";

	cout << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 3;
	//cin >> t;
	cin >> N;
	while (t--) solve();
	return 0;
}

int DP(int pos, int turn) {
	if (pos == 0) return 0;
	int& ret = table[pos][turn];
	if (ret != INF) return ret;

	if (turn) {
		ret = -INF;
		for (int i = pos; i >= 1; i--) ret = max(ret, DP(i - 1, turn ^ 1));
	}
	else {
		ret = INF - 1;
		for (int i = pos; i >= 1; i--) ret = min(ret, psum[pos] - psum[i - 1] + DP(i - 1, turn ^ 1));
	}

	return ret;
}