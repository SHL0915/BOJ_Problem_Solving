#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, T, M, S, E;
int table[10001][1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T >> M;
	cin >> S >> E;
	memset(table, INF, sizeof(table));
	table[S][0] = 0;
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < M; j++) {
			int A, B, C;
			cin >> A >> B >> C;
			table[A][i] = min(table[A][i - 1], table[A][i]);
			table[A][i] = min(table[A][i], table[B][i - 1] + C);
			table[B][i] = min(table[B][i - 1], table[B][i]);
			table[B][i] = min(table[B][i], table[A][i - 1] + C);
		}
		for (int j = 0; j <= N; j++) table[j][i] = min(table[j][i], table[j][i - 1]);
	}
	if (table[E][T] == INF) cout << -1;
	else cout << table[E][T];
	return 0;
}