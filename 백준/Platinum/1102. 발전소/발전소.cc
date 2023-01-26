#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, P, ans = INF;
int arr[20][20];
int table[(1 << 20)];
string S;

int DP(int state, int cnt);
int strtoint(string s);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	cin >> S;
	cin >> P;
	memset(table, -1, sizeof(table));
	int state = strtoint(S);
	int cnt = 0;
	for (int i = 0; i < S.length(); i++) if (S[i] == 'Y') cnt++;
	int ans = DP(state, cnt);
	if (ans == INF) cout << -1;
	else cout << DP(state, cnt);
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

int DP(int state, int cnt) {
	if (cnt >= P) return 0;
	int& ret = table[state];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < N; i++) {
		if (!(state & (1 << i))) continue;
		for (int j = 0; j < N; j++) {
			if (state & (1 << j)) continue;
			ret = min(ret, arr[i][j] + DP(state | (1 << j), cnt + 1));
		}
	}
	return ret;
}

int strtoint(string s) {
	int ret = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		ret *= 2;
		if (s[i] == 'Y') ret += 1;
	}
	return ret;
}