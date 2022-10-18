#include <iostream>
using namespace std;

int N, R, S, X, Y, W;

int comb[11][11];

int combination(int n, int r);
long long power(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> R >> S >> X >> Y >> W;
		long long temp = 0;
		for (int i = X; i <= Y; i++) temp += power(S - R + 1, i) * power(R - 1, Y - i) * W * combination(Y, i);
		if (temp > power(S, Y)) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}

int combination(int n, int r) {
	if (r == 0 || r == n) return 1;
	else if (comb[n][r] == 0) comb[n][r] = combination(n - 1, r) + combination(n - 1, r - 1);
	return comb[n][r];
}

long long power(int a, int b) {
	long long result = 1;
	for (int i = 0; i < b; i++) result *= a;
	return result;
}