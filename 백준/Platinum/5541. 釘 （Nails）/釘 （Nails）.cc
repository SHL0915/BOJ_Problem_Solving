#include <iostream>
#include <algorithm>
using namespace std;

int N, M, cnt;
int table[5001][5001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		table[A][B] = max(table[A][B], C + 1);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int val;
			val = max(table[i - 1][j] - 1, table[i - 1][j - 1] - 1);
			val = max(val, table[i][j]);
			if (val != 0) cnt++;
			table[i][j] = val;
		}
	}
	cout << cnt;
	return 0;
}