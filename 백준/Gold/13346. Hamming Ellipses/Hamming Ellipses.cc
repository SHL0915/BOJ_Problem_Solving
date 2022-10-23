#include <iostream>
using namespace std;

long long Q, N, D;
string A, B;
long long table[101][201];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> Q >> N >> D;
	cin >> A >> B;
	A = A;
	B = B;
	if (A[0] == B[0]) {
		table[0][0] = 1;
		table[0][2] = Q - 1;
	}
	else {
		table[0][1] = 2;
		table[0][2] = Q - 2;
	}
	for (int i = 1; i < N; i++) {
		if (A[i] == B[i]) {
			table[i][0] = table[i - 1][0];
			table[i][1] = table[i - 1][1];
			table[i][2] = table[i - 1][2] + table[i - 1][0] * (Q - 1);
			for (int j = 3; j <= D; j++) table[i][j] = table[i - 1][j] + table[i - 1][j - 2] * (Q - 1);
			
		}
		else {
			table[i][1] = table[i - 1][0] * 2;
			table[i][2] = table[i - 1][1] * 2 + table[i - 1][0] * (Q - 2);
			for (int j = 3; j <= D; j++) table[i][j] = table[i - 1][j - 2] * (Q - 2) + table[i - 1][j - 1] * 2;
		}
	}
	cout << table[N - 1][D];
	return 0;
}