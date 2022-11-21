#include <iostream>
using namespace std;

int N;
int table[31];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	table[0] = 1;
	table[1] = 1;
	for (int i = 2; i <= N; i++) table[i] = table[i - 1] + 2 * table[i - 2];
	if (N % 2 == 0) {
		table[N] += (table[N / 2] + table[N / 2 - 1] * 2);
		cout << table[N] / 2;
	}
	else {
		table[N] += table[N / 2];
		cout << table[N] / 2;
	}
	return 0;
}