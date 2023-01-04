#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;

int N, M, C;
int arr[51][51];
int table[51][51][51][51];

int DP(int x, int y, int k, int m);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> C;
	for (int i = 1; i <= C; i++) {
		int x, y;
		cin >> y >> x;
		arr[y][x] = i;
	}
	memset(table, -1, sizeof(table));
	for (int i = 0; i <= C; i++) cout << DP(1, 1, i, 0) << " ";
	return 0;
}

int DP(int x, int y, int k, int m) {
	if (k < 0) return 0;
	if (x > M || y > N) return 0;
	if (x == M && y == N) {
		if (arr[y][x]) return (k == 1 && m < arr[y][x]);
		else return (k == 0);
	}
	int& ret = table[x][y][k][m];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[y][x]) {
		if (k > 0 && m < arr[y][x]) {
			ret += DP(x + 1, y, k - 1, arr[y][x]);
			ret += DP(x, y + 1, k - 1, arr[y][x]);
		}
	}
	else {
		ret += DP(x + 1, y, k, m);
		ret += DP(x, y + 1, k, m);
	}
	ret %= mod;
	return ret;
}