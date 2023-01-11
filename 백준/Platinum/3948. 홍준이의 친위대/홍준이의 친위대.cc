#include <bits/stdc++.h>
using namespace std;

int T, N;
long long table[21][21][21][2];

long long DP(int pos, int up, int down, int mode);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(table, -1, sizeof(table));
	cin >> T;
	while (T--) {
		cin >> N;
		if (N == 1) {
			cout << 1 << '\n';
			continue;
		}
		long long ans = 0;
		for (int i = 1; i <= N; i++) {
			ans += DP(0, N - i, i - 1, 0);
			ans += DP(0, N - i, i - 1, 1);
		}
		cout << ans << '\n';
	}
	return 0;
}

long long DP(int pos, int up, int down, int mode) {
	if (pos == N - 1) return 1;
	long long& ret = table[pos][up][down][mode];
	if (ret != -1) return ret;
	ret = 0;
	if (mode) for (int i = 0; i < down; i++) ret += DP(pos + 1, up + i, down - i - 1, mode ^ 1);
	else for (int i = 0; i < up; i++) ret += DP(pos + 1, up - i - 1, down + i, mode ^ 1);
	return ret;
}