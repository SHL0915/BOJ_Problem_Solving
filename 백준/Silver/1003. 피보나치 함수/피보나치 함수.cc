#include <iostream>
using namespace std;

int T, N;
long long table[41][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	table[0][0] = 1;
	table[1][0] = 0;
	table[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		table[i][0] = table[i - 1][0] + table[i - 2][0];
		table[i][1] = table[i - 1][1] + table[i - 2][1];
	}
	cin >> T;
	while (T--) {
		cin >> N;
		cout << table[N][0] << " " << table[N][1] << '\n';
	}
	return 0;
}