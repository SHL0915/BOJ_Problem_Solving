#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int S, A, B, C;
long long table[51][51][51][51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> A >> B >> C;
	table[0][0][0][0] = 1;
	for (int i = 1; i <= S; i++) {
		for (int j = 0; j <= A; j++) {
			for (int k = 0; k <= B; k++) {
				for (int l = 0; l <= C; l++) {
					if (j > 0) {
						table[i][j][k][l] += table[i- 1][j - 1][k][l];
						table[i][j][k][l] %= mod;
					}
					if (k > 0) {
						table[i][j][k][l] += table[i - 1][j][k - 1][l];
						table[i][j][k][l] %= mod;
					}
					if (l > 0) {
						table[i][j][k][l] += table[i - 1][j][k][l - 1];
						table[i][j][k][l] %= mod;
					}
					if (j > 0 && k > 0) {
						table[i][j][k][l] += table[i - 1][j - 1][k - 1][l];
						table[i][j][k][l] %= mod;
					}
					if (j > 0 && l > 0) {
						table[i][j][k][l] += table[i - 1][j - 1][k][l - 1];
						table[i][j][k][l] %= mod;
					}
					if (k > 0 && l > 0) {
						table[i][j][k][l] += table[i - 1][j][k - 1][l - 1];
						table[i][j][k][l] %= mod;
					}
					if (j > 0 && k > 0 && l > 0) {
						table[i][j][k][l] += table[i - 1][j - 1][k - 1][l - 1];
						table[i][j][k][l] %= mod;
					}
				}
			}
		}
	}
	cout << table[S][A][B][C];
	return 0;
}