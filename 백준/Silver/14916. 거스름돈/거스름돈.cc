#include <iostream>
using namespace std;

int table[100000];
int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	table[2] = 1;
	table[4] = 2;
	table[5] = 1;
	for (int i = 6; i <= n; i++) {
		int A = 0, B = 0;
		if (table[i - 5] != 0) A = table[i - 5] + 1;
		if (table[i - 2] != 0) B = table[i - 2] + 1;
		if (A == 0 && B == 0) continue;
		else if (A == 0) table[i] = B;
		else if (B == 0) table[i] = A;
		else table[i] = min(A, B);
	}
	if (table[n] == 0) cout << -1;
	else cout << table[n];
	return 0;
}