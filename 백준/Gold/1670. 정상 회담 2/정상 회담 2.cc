#include <bits/stdc++.h>
using namespace std;
const int mod = 987654321;

int N;
long long table[10001];

long long DP(int n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	memset(table, -1, sizeof(table));
	cout << DP(N) << endl;
	return 0;
}

long long DP(int n) {
	if (n == 0 || n == 1) return n ^= 1;
	if (table[n] != -1) return table[n];
	table[n] = 0;
	for (int i = 0; i < n - 1; i++) {
		table[n] += ((DP(i) % mod) * (DP(n - i - 2) % mod)) % mod;		
		table[n] %= mod;
	}
	return table[n];
}