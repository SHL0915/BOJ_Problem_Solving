#include <bits/stdc++.h>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

int N, L, ans;
int arr[20][20];
int table[20][20][20][20][21];

int DP(int sx, int sy, int ex, int ey, int k);
int absol(int A) {
	if (A < 0) return -A;
	else return A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	memset(table, -1, sizeof(table));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++)	ans += DP(i, j, a, b, L - 1);				
			}
		}
	}
	cout << ans;
	return 0;
}

int DP(int sx, int sy, int ex, int ey, int k) {
	if (sx < 0 || sx > N - 1 || sy < 0 || sy > N - 1 || ex < 0 || ex > N - 1 || ex < 0 || ey > N - 1) return 0;
	if (arr[sy][sx] != arr[ey][ex]) return 0;
	if (k == 0) return (sx == ex && sy == ey);
	if (k == 1) return (max({ absol(sx - ex),absol(sy - ey) }) == 1);
	int& ret = table[sx][sy][ex][ey][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int n_sx = sx + dx[i];
			int n_sy = sy + dy[i];
			int n_ex = ex + dx[j];
			int n_ey = ey + dy[j];
			ret += DP(n_sx, n_sy, n_ex, n_ey, k - 2);
		}
	}
	return ret;
}