#include <bits/stdc++.h>
using namespace std;

int N, M;
long long table[21][21];

long long GCD(long long A, long long B) {
	if (A > B) {
		if (A % B == 0) return B;
		else return GCD(A % B, B);
	}
	else {
		if (B % A == 0) return A;
		else return GCD(B % A, A);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	table[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			table[i][j] = (i - 1) * table[i-1][j] + table[i-1][j-1];
		}
	}
	long long ans = 0;
	for (int i = 1; i <= M; i++) ans += table[N][i];
	long long tot = 1;
	for (int i = 1; i <= N; i++) tot *= i;
	cout << ans / GCD(tot, ans) << "/" << tot / GCD(tot, ans);
	return 0;
}