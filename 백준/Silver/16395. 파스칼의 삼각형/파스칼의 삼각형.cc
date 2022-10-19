#include <iostream>
using namespace std;

int n, k;
long long comb[31][31];

long long combination(int n, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cout << combination(n - 1, k - 1);
	return 0;
}

long long combination(int n, int k) {
	if (k == 0 || k == n) return 1;
	else if (comb[n][k] == 0) comb[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
	return comb[n][k];
}