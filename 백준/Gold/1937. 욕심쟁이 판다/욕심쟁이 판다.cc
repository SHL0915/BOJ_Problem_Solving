#include <iostream>
#include <algorithm>
using namespace std;

int N, ans, max_val;
pair <int, int> max_pos;
int forest[500][500];
int table[500][500];
int mark[500][500];

int DP(int x, int y, int prev);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> forest[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) ans = max(ans, DP(j, i, -1));
	}	
	cout << ans;
	return 0;
}

int DP(int x, int y, int prev) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return -1;
	if (forest[y][x] <= prev) return -1;
	if (table[y][x] != 0) return table[y][x];
	table[y][x] = 1;
	int A, B, C, D;
	A = DP(x + 1, y, forest[y][x]);
	B = DP(x - 1, y, forest[y][x]);
	C = DP(x, y - 1, forest[y][x]);
	D = DP(x, y + 1, forest[y][x]);
	table[y][x] = max(table[y][x], A + 1);
	table[y][x] = max(table[y][x], B + 1);
	table[y][x] = max(table[y][x], C + 1);
	table[y][x] = max(table[y][x], D + 1);
	return table[y][x];
}