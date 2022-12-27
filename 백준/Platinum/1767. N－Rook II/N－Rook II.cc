#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000001;

ll N, M, K;
ll table[101][101][101];

ll DP(ll n, ll m, ll k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	memset(table, -1, sizeof(table));
	cout << DP(N, M, K);
	return 0;
}

ll DP(ll n, ll m, ll k) {
	if (n < 0 || m < 0 || k < 0) return 0;
	if (k == 0) return 1;
	ll& ret = table[n][m][k];
	if (ret != -1) return ret;
	ret = 0;
	ret += DP(n - 1, m, k);
	ret += DP(n - 1, m - 1, k - 1) * m;
	ret += DP(n - 1, m - 2, k - 2) * m * (m - 1) / 2;
	ret += DP(n - 2, m - 1, k - 2) * m * (n - 1);
	ret %= mod;
	return ret;
}