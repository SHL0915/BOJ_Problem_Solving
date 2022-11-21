#include <iostream>
using namespace std;

int T, N, L, R;
long long table[21][21][21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> L >> R;
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				for (int k = 0; k <= 20; k++) table[i][j][k] = 0;
			}
		}
		table[1][1][1] = 1;
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= L; j++) {
				for (int k = 1; k <= R; k++) {
					table[i][j][k] += table[i - 1][j - 1][k];
					table[i][j][k] += table[i - 1][j][k - 1];
					table[i][j][k] += table[i - 1][j][k] * (i - 2);
				}
			}			
		}
		cout << table[N][L][R] << '\n';
	}
	return 0;
}