#include <iostream>
using namespace std;

int N, M;
int table[1025][1025];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> table[i][j];
			table[i][j] = table[i][j] + table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
		}
	}
	for (int i = 0; i < M; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << table[x2][y2] - table[x2][y1 - 1] - table[x1 - 1][y2] + table[x1 - 1][y1 - 1] << "\n";
	}
	return 0;
}