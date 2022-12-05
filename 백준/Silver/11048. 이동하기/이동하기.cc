#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1000][1000];
int table[1000][1000];

int DP(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
	memset(table, -1, sizeof(table));
	DP(0, 0);
	cout << DP(M - 1, N - 1);
	return 0;
}

int DP(int x, int y) {
	if (x < 0 || y < 0 || x > M - 1 || y > N - 1) return 0;
	if (table[y][x] != -1) return table[y][x];
	table[y][x] = arr[y][x];
	int temp = max(DP(x - 1, y), DP(x, y - 1));
	temp = max(temp, DP(x - 1, y - 1));
	table[y][x] += temp;
	return table[y][x];
}