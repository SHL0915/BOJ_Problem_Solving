#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
string S;
int table[101][101][3];

int DP(int left, int right, int color);

void solve() {
	cin >> N >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'R') S[i] = '0';
		else if (S[i] == 'G') S[i] = '1';
		else S[i] ='2';
	}
	memset(table, -1, sizeof(table));
	cout << 1 + DP(0, N - 1, S[0] - '0');
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

int DP(int left, int right, int color) {
	if (left >= N) return 0;
	if (left == right) return (S[left] - '0' != color);
	if (S[left] - '0' == color) return DP(left + 1, right, color);
	int& ret = table[left][right][color];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = left; i <= right; i++) {
		if (S[i] == S[left]) ret = min(ret, 1 + DP(left, i, S[left] - '0') + DP(i + 1, right, color));
	}
	return ret;
}