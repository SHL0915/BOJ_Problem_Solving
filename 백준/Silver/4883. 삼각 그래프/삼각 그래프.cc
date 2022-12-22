#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, TC;
ll graph[100000][3];
ll table[100000][3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		TC++;
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
		memset(table, 0, sizeof(table));
		table[0][0] = INF;
		table[0][1] = graph[0][1];
		table[0][2] = graph[0][1] + graph[0][2];
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				table[i][j] = graph[i][j];
				if (j == 0) table[i][j] += min(table[i - 1][j], table[i - 1][j + 1]);
				else if (j == 1) table[i][j] += min({ table[i - 1][j - 1], table[i - 1][j], table[i - 1][j + 1], table[i][j - 1] });
				else table[i][j] += min({ table[i - 1][j - 1], table[i - 1][j], table[i][j - 1] });
			}
		}
		cout << TC << ". " << table[N - 1][1] << '\n';
	}
	return 0;
}