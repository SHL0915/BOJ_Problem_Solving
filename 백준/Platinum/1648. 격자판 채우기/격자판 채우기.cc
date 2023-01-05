#include <bits/stdc++.h>
using namespace std;
const int mod = 9901;

int N, M;
int table[15][15][(1 << 15)];

int DP(int x, int y, int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0);
	return 0;
}

int DP(int x, int y, int state) {
	if (state & 1) return DP((x + 1) % M, y + (x + 1) / M, state >> 1);
	if (y == N) return 1;
	int& ret = table[x][y][state];
	if (ret != -1) return ret;
	ret = 0;
	if (x < M - 1 && ((state & 2) == 0)) ret += DP((x + 2) % M, y + (x + 2) / M, state >> 2);
	if (y < N - 1) ret += DP((x + 1) % M, y + (x + 1) / M, (state | (1 << M)) >> 1);
	ret %= mod;
	return ret;
}