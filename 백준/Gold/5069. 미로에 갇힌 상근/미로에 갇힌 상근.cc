#include <bits/stdc++.h>
using namespace std;

int t, N;
long long table[300][300][15];

long long DP(int x, int y, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	memset(table, -1, sizeof(table));
	while (t--) {
		cin >> N;
		cout << DP(150, 150, N) << '\n';
	}
	return 0;
}

long long DP(int x, int y, int k) {
	if (k == 0) return (x == 150 && y == 150);
	long long& ret = table[x][y][k];
	if (ret != -1) return ret;	
	ret = DP(x + 1, y, k - 1) + DP(x - 1, y, k - 1) + DP(x, y - 1, k - 1) + DP(x + 1, y - 1, k - 1) + DP(x - 1, y + 1, k - 1) + DP(x, y + 1, k - 1);
	return ret;
}