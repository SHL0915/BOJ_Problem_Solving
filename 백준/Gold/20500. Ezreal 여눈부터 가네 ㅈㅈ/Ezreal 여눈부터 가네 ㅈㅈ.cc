#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1000000007;

int N;
int table[1516][15];
int arr[2][1516];

int DP(int pos, int k);

void solve() {
	cin >> N;
	arr[0][0] = 1;
	arr[1][0] = 5;
	for (int i = 1; i <= N; i++) {
		arr[0][i] = (arr[0][i - 1] * 10) % 15;
		arr[1][i] = (arr[1][i - 1] * 10) % 15;
	}
	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int pos, int k) {
	if (pos == N) return (k == 0);
	int& ret = table[pos][k];
	if (ret != -1) return ret;
	ret = 0;
	ret += DP(pos + 1, (k + arr[0][pos]) % 15);
	ret += DP(pos + 1, (k + arr[1][pos]) % 15);
	ret %= mod;
	return ret;
}