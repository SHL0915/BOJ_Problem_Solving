#include <bits/stdc++.h>
using namespace std;

double A, B;
double table[91][20][20];
int primeNum[8] = { 2,3,5,7,11,13,17, 19 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(12);
	cin >> A >> B;
	table[0][0][0] = 1;
	for (int i = 5; i <= 90; i += 5) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < 20; k++) {
				table[i][j][k] += table[i - 5][j][k] * (100 - A) / 100 * (100 - B) / 100;
				if (j > 0) table[i][j][k] += table[i - 5][j - 1][k] * A / 100 * (100 - B) / 100;
				if (k > 0) table[i][j][k] += table[i - 5][j][k - 1] * (100 - A) / 100 * B / 100;
				if (j > 0 && k > 0) table[i][j][k] += table[i - 5][j - 1][k - 1] * A / 100 * B / 100;
			}
		}
	}
	double ans = 0;
	for (int j = 0; j < 20; j++) {
		for (int k = 0; k < 20; k++) {
			int flag = 0;
			for (int i = 0; i < 8; i++) {
				if (j == primeNum[i] || k == primeNum[i]) flag = 1;
			}
			if (flag == 1) ans += table[90][j][k];
		}
	}
	cout << ans;
	return 0;
}