#include <iostream>
using namespace std;

int N;
int weight[500];
int table[500][500];

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) cin >> weight[i];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) table[i][j] = 0;
		}
		for (int i = 1; i <= N; i++) {
			if (i == 2) {
				for (int j = 0; j < N - 1; j++) {
					if (absol(weight[j] - weight[j + 1]) <= 1) table[j][j + 1] = 2;
				}
			}
			else {
				for (int j = 0; j < N - i + 1; j++) {
					for (int k = j; k < j + i - 1; k++) table[j][j + i - 1] = max(table[j][j + i - 1], table[j][k] + table[k + 1][j + i - 1]);
					if (i % 2 == 0 && absol(weight[j] - weight[j + i - 1]) <= 1 && table[j + 1][j + i - 2] == i - 2) table[j][j + i - 1] = i;
				}
			}
		}
		cout << table[0][N - 1] << '\n';
	}
	return 0;
}