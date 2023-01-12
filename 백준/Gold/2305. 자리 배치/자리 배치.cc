#include <bits/stdc++.h>
using namespace std;

int N, K;
int table[41][2];
int f[41];

int DP(int n, bool k = false) {
	int& ret = table[n][k];
	if (ret != -1) return ret;
	if (n == 0) return ret = k;
	ret = DP(n - 1, k);
	if (n > 1) ret += DP(n - 2, k);
	if (!k) {
		for (int i = n - 1; i >= 0; i--) ret += DP(i, true) * (i == n - 1 ? 1 : 2);
	}
	return ret;
}

int main() {
	cin >> N >> K;
	f[0] = f[1] = 1;
	for (int i = 2; i <= 40; i++) f[i] = f[i - 1] + f[i - 2];
	int L = K - 1, R = N - K;
	memset(table, -1, sizeof(table));
	cout << f[L] * f[R] + DP(L) * f[R] + DP(R) * f[L];
}