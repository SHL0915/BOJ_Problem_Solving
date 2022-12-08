#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000003;

int N, K;
long long ans;
long long table1[1001][1001][2];
long long table2[1001][1001][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	table1[1][1][1] = 1;
	table2[1][0][0] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			table1[i][j][0] = (table1[i - 1][j][0] + table1[i - 1][j][1]) % mod;
			table2[i][j][0] = (table2[i - 1][j][0] + table2[i - 1][j][1]) % mod;
			table1[i][j][1] = table1[i - 1][j - 1][0];
			table2[i][j][1] = table2[i - 1][j - 1][0];
		}
	}
	ans = (table1[N][K][0] + table2[N][K][0] + table2[N][K][1]) % mod;
	cout << ans;
	return 0;
}