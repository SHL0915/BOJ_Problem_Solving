#include <bits/stdc++.h>
using namespace std;

int N;
char arr[12][12];
int val[91][91];
int table[12][12][(1 << 12)];

void putval();
int DP(int x, int y, int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	putval();
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) arr[i][j] = s[j];
	}
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 0);
	return 0;
}

int DP(int x, int y, int state) {
	if (state & 1) return DP((x + 1) % N, y + (x + 1) / N, state >> 1);
	if (x == N && y == N) return 0;
	int& ret = table[x][y][state];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, DP((x + 1) % N, y + (x + 1) / N, state >> 1));
	if (x < N - 1 && (state & 2) == 0) ret = max(ret, val[arr[y][x]][arr[y][x + 1]] + DP((x + 2) % N, y + (x + 2) / N, state >> 2));
	if (y < N - 1) ret = max(ret, val[arr[y][x]][arr[y + 1][x]] + DP((x + 1) % N, y + (x + 1) / N, (state | (1 << N)) >> 1));
	return ret;
}

void putval() {
	val['A']['A'] = 100;
	val['A']['B'] = 70;
	val['A']['C'] = 40;
	val['B']['A'] = 70;
	val['B']['B'] = 50;
	val['B']['C'] = 30;
	val['C']['A'] = 40;
	val['C']['B'] = 30;
	val['C']['C'] = 20;	
	return;
}