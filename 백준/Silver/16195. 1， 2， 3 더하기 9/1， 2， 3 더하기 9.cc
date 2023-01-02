#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000009;

int t, N, M;
long long table[1001][1001];

long long DP(int now, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	memset(table, -1, sizeof(table));
	while (t--) {
		cin >> N >> M;
		cout << DP(N, M) << '\n';
	}
	return 0;
}

long long DP(int now, int k) {
	if (now < 0) return 0;
	if (now == 0) return (k >= 0);
	if (k < 0) return 0;
	long long& ret = table[now][k];
	if (ret != -1) return ret;
	ret = 0;
	ret += DP(now - 1, k - 1);
	ret += DP(now - 2, k - 1);
	ret += DP(now - 3, k - 1);
	ret %= mod;
	return ret;
}