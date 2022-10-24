#include <iostream>
using namespace std;

int T, N, M;
long long table[31][31];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;		
		table[1][0] = 1;
		table[1][1] = 1;
		for (int i = 2; i <= M; i++) {
			table[i][0] = 1;
			for (int j = 1; j <= N; j++) {
				if (j > i) break;
				table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
			}
		}
		cout << table[M][N] << '\n';
	}
	return 0;
}