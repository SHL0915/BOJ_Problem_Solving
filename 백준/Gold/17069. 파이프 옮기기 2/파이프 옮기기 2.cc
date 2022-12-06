#include <bits/stdc++.h>
using namespace std;

int N;
int arr[35][35];
long long table[35][35][3];

long long DP(int x, int y, int state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	memset(table, -1, sizeof(table));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}
	table[1][2][0] = 1;
	cout << DP(N, N, 0) + DP(N, N, 1) + DP(N, N, 2);
	return 0;
}

long long DP(int x, int y, int state) {
	if (x < 1 || x > N || y < 1 || y > N) return 0;
	if (table[y][x][state] != -1) return table[y][x][state];
	if (state == 0) {
		if (arr[y][x] + arr[y][x - 1] != 0) return 0;
		table[y][x][state] = DP(x - 1, y, 0) + DP(x - 1, y, 1);
	}
	else if (state == 1) {
		if (arr[y][x] + arr[y - 1][x] + arr[y][x - 1] + arr[y - 1][x - 1] != 0) return 0;
		table[y][x][state] = DP(x - 1, y - 1, 0) + DP(x - 1, y - 1, 1) + DP(x - 1, y - 1, 2);
	}
	else {
		if (arr[y][x] + arr[y - 1][x] != 0) return 0;
		table[y][x][state] = DP(x, y - 1, 1) + DP(x, y - 1, 2);
	}
	return table[y][x][state];
}