#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
int arr[1000][1000];
long long table[1000][1000][2];

long long DP(int x, int y, int dir);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	memset(table, -1, sizeof(table));
	cout << DP(0, 0, 1);
	return 0;
}

long long DP(int x, int y, int dir) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return -INF;
	if (x == M - 1 && y == N - 1) return arr[y][x];
	long long& ret = table[y][x][dir];
	if (ret != -1) return ret;
	ret = -INF;
	if (dir) ret = max(ret, arr[y][x] + DP(x + 1, y, dir));
	else ret = max(ret, arr[y][x] + DP(x - 1, y, dir));
	ret = max(ret, arr[y][x] + DP(x, y + 1, 0));
	ret = max(ret, arr[y][x] + DP(x, y + 1, 1));
	return ret;
}