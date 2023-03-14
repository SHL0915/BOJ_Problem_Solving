#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int sieve[1500];
ll table[1500][15][250];
vector <int> primeNum;

ll DP(int now, int k, int idx);

void solve() {
	cin >> N >> K;
	cout << DP(N, K, primeNum.size() - 1) << '\n';

}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < 1500; i++) {
		if (sieve[i] == 0) {
			primeNum.push_back(i);
			for (int j = i; j < 1500; j += i) sieve[j] = 1;
		}
	}

	memset(table, -1, sizeof(table));

	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

ll DP(int now, int k, int idx) {
	if (k == 0) {
		if (now == 0) return 1;
		else return 0;
	}

	if (now <= 0) return 0;

	ll& ret = table[now][k][idx];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= idx; i++) {
		int val = primeNum[i];
		ret += DP(now - val, k - 1, i - 1);
	}

	return ret;
}