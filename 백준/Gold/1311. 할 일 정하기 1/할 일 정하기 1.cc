#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans = 1234567890;
int arr[21][21];
int table[(1 << 21)];

int DP(int state, int now);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	memset(table, INF, sizeof(table));
	cout << DP(0, 0);
	return 0;
}

int DP(int state, int now) {
	if (state == (1 << N) - 1) return 0;
	if (table[state] != INF) return table[state];
	for (int i = 0; i < N; i++) {
		if (state & (1 << i)) continue;
		table[state] = min(table[state], DP(state ^ (1 << i), now + 1) + arr[now][i]);
	}
	return table[state];
}