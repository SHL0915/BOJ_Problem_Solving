#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, K, ans;
int arr[20][20];
int table[(1 << 20)];

int DP(int state);
int count_bit(int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	memset(table, INF, sizeof(table));
	cout << DP((1 << N) - 1);
	return 0;
}

int DP(int state) {
	if (popcount((unsigned int)state) <= K) return 0;
	if (table[state] != INF) return table[state];
	for (int i = 0; i < N; i++) {
		if (!(state & (1 << i))) continue;
		for (int j = 0; j < N; j++) {
			if (!(state & (1 << j))) continue;
			if (i == j) continue;
			table[state] = min(table[state], DP(state ^ (1 << i)) + arr[i][j]);
		}
	}
	return table[state];
}