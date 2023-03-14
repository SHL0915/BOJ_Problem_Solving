#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
string org, S;
int table[51][51];

int DP(int a, int b);

void solve() {
	cin >> org;
	N = org.length();
	ans = 0x3f3f3f3f;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			S = org;
			swap(S[i], S[j]);
			memset(table, -1, sizeof(table));
			ans = min(ans, 1 + DP(0, N - 1));
		}
	}

	S = org;
	memset(table, -1, sizeof(table));
	ans = min(ans, DP(0, N - 1));

	cout << ans;
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int a, int b) {	
	if (a >= b) return 0;
	int& ret = table[a][b];
	if (ret != -1) return ret;
	ret = 0x3f3f3f3f;

	if (S[a] == S[b]) ret = min(ret, DP(a + 1, b - 1));
	ret = min(ret, 1 + DP(a, b - 1));
	ret = min(ret, 1 + DP(a + 1, b));
	ret = min(ret, 1 + DP(a + 1, b - 1));

	return ret;
}