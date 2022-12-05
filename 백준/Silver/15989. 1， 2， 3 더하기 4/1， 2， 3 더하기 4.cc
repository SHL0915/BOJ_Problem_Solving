#include <bits/stdc++.h>
using namespace std;

int T, N;
int table[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		memset(table, 0, sizeof(table));
		table[0] = 1;
		for (int i = 1; i <= 3; i++) {
			for (int j = 0; j <= N; j++) {
				if (i > j) continue;
				table[j] += table[j - i];
			}
		}
		cout << table[N] << '\n';
	}
	return 0;
}