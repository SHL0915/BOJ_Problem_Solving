#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 10;

int N;
string A, B;
int table[10001][10];

int DP(int pos, int left);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B;
	memset(table, -1, sizeof(table));
	cout << DP(0, 0);
	return 0;
}

int DP(int pos, int left) {
	if (pos == N) return 0;
	int& ret = table[pos][left];
	if (ret != -1) return ret;
	ret = INF;
	int now = (A[pos] - '0' + left) % mod;
	int rcost = ((now - (B[pos] - '0')) + mod) % mod;
	int lcost = ((B[pos] - '0' - now) + mod) % mod;
	ret = min(ret, rcost + DP(pos + 1, left));
	ret = min(ret, lcost + DP(pos + 1, (left + lcost) % mod));
	return ret;
}