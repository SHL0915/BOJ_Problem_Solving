#include <iostream>
using namespace std;

int n;
int table[251][201];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	table[0][200] = 0;
	table[1][200] = 1;
	table[2][200] = 3;
	for (int i = 3; i <= 250; i++) {
		for (int j = 200; j >= 1; j--) {
			table[i][j] += (table[i - 1][j] + 2 * table[i - 2][j]);
			table[i][j - 1] += (table[i][j] / 10);
			table[i][j] %= 10;
		}
	}
	while (cin >> n) {
		if (n == 0) cout << 1;
		else {
			int flag = 0;
			for (int i = 0; i < 201; i++) {
				if (table[n][i] != 0) flag = 1;
				if (flag != 0) cout << table[n][i];
			}
		}
		cout << "\n";
	}
	return 0;
}