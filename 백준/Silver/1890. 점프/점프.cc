#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100][100];
long long table[100][100];

long long DP(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}	
	memset(table, -1, sizeof(table));
	table[N - 1][N - 1] = 1;
	cout << DP(0, 0) << endl;	
	return 0;
}

long long DP(int x, int y) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return 0;
	if (table[y][x] != -1) return table[y][x];
	if (arr[y][x] == 0) table[y][x] = 0;
	else table[y][x] = DP(x + arr[y][x], y) + DP(x, y + arr[y][x]);
	return table[y][x];
}