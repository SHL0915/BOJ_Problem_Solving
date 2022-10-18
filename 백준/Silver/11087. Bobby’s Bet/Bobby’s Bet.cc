#include <iostream>
using namespace std;

int N, R, S, X, Y, W;

int comb[11][11];

int combination(int n, int r);
double power(double a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> R >> S >> X >> Y >> W;
		double temp = 0;
		double a = (S - R + 1) / (double)S;
		double b = (R - 1) / (double)S;
		for (int i = X; i <= Y; i++) {
			temp += power(a, i) * power(b, Y - i) * W * combination(Y, i);
		}
		if (temp > 1) cout << "yes\n";
		else cout << "no\n";
	} 
	return 0;
}

int combination(int n, int r) {
	if (r == 0 || r == n) return 1;
	else if (comb[n][r] == 0) comb[n][r] = combination(n - 1, r) + combination(n - 1, r - 1);
	return comb[n][r];
}

double power(double a, int b) {
	double result = 1;
	for (int i = 0; i < b; i++) result *= a;
	return result;
}