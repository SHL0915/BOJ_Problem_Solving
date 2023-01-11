#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 10;

int N;
string a, b;
int A[10001], B[10001];
int table[10001][10];
int ans[10001][10];

int DP(int pos, int left);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> a >> b;
	for (int i = 0; i < a.length(); i++) A[i] = a[i] - '0';
	for (int i = 0; i < b.length(); i++) B[i] = b[i] - '0';
	memset(table, -1, sizeof(table));
	cout << DP(0, 0) << '\n';
	int pos = 0, now = 0;
	while (pos < N) {
		int val = ans[pos][now];
		if (val != 0) cout << pos + 1 << " " << val << '\n';
		pos++;
		if (val > 0) now = (now + val) % mod;
	}
	return 0;
}

int DP(int pos, int left) {
	if (pos == N) return 0;
	int& ret = table[pos][left];
	if (ret != -1) return ret;
	ret = INF;
	int now = (A[pos] + left) % mod;
	int rcost = ((now - B[pos]) + mod) % mod;
	int lcost = ((B[pos] - now) + mod) % mod;
	if (rcost + DP(pos + 1, left) < lcost + DP(pos + 1, (left + lcost) % mod)) ans[pos][left] = -rcost;
	else ans[pos][left] = lcost;
	ret = min(ret, rcost + DP(pos + 1, left));
	ret = min(ret, lcost + DP(pos + 1, (left + lcost) % mod));
	return ret;
}