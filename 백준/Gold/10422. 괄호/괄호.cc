#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int T, L;
long long table[2501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> L;		
		if (L % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}
		L /= 2;
		for (int i = 0; i <= 2500; i++) table[i] = 0;
		table[0] = 1;
		for (int i = 1; i <= L; i++) {
			for (int j = 0; j <= L - 1; j++) table[i] = (table[i] + (table[j] * table[i - j - 1])) % mod;
		}
		cout << table[L] << '\n';
	}
	return 0;
}