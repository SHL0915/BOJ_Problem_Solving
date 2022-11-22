#include <bits/stdc++.h>
using namespace std;

const int INF = 1234567890;

int N, P, ans;
string S;
int cost[16][16];
int table[(1 << 16)];

int strtoi(string s);
int DP(int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> cost[i][j];
	}
	memset(table, -1, sizeof(table));
	cin >> S;
	cin >> P;
	ans = DP(strtoi(S));
	if (P == 0) cout << 0;
	else if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

int strtoi(string s) {
	int ret = 0;
	int bit = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'Y') ret += bit;		
		bit <<= 1;
	}
	return ret;
}

int DP(int state) {
	if (table[state] != -1) return table[state];
	int cnt = popcount((unsigned int)state);
	if (cnt >= P) return 0;
	table[state] = INF;
	for (int i = 0; i < N; i++) {
		if (!(state & (1 << i))) continue;
		for (int j = 0; j < N; j++) {
			if (state & (1 << j)) continue;
			table[state] = min(table[state], cost[i][j] + DP(state | (1 << j)));
		}
	}
	return table[state];
}