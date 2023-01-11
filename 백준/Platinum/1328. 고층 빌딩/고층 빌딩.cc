#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int N, L, R;
long long table[101][101][101];

long long DP(int pos, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L >> R;
	memset(table, -1, sizeof(table));
	cout << DP(1, 1, 1);
	return 0;
}

long long DP(int pos, int left, int right) {
	if (left > L || right > R) return 0;
	if (pos == N) return (left == L && right == R);
	long long& ret = table[pos][left][right];
	if (ret != -1) return ret;
	ret = 0;
	ret += DP(pos + 1, left + 1, right);
	ret += DP(pos + 1, left, right + 1);
	ret += (pos - 1) * DP(pos + 1, left, right);
	ret %= mod;
	return ret;
}