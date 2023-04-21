#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int table[5001][10001];

void solve() {
	cin >> N >> M;
	memset(table, -1, sizeof(table));

	table[0][M] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			table[i][j] = max(table[i][j], table[i - 1][j]);
			if (j + 1 <= M && table[i - 1][j + 1] != -1) table[i][j] = max(table[i][j], 1 + table[i - 1][j + 1]);
			if (j + 3 <= M && table[i - 1][j + 3] != -1) table[i][j] = max(table[i][j], 2 + table[i - 1][j + 3]);
			if (j + 7 <= M && table[i - 1][j + 7] != -1) table[i][j] = max(table[i][j], 4 + table[i - 1][j + 7]);
			if (j + 15 <= M && table[i - 1][j + 15] != -1) table[i][j] = max(table[i][j], table[i - 1][j + 15]);
		}
	}
	
	cout << table[N][0];
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}