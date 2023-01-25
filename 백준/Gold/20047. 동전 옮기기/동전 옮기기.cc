#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
char a, b;
string S, T;
int table[10001][3];

int DP(int a_pos, int b_pos, int mode);

void solve() {
	cin >> N;
	string s, t;
	cin >> s >> T;
	int aa, bb;
	cin >> aa >> bb;
	a = s[aa];
	b = s[bb];
	for (int i = 0; i < s.length(); i++) {
		if (i == aa || i == bb) continue;
		S += s[i];
	}
	memset(table, -1, sizeof(table));
	int ans = DP(0, 0, 0);
	if (ans) cout << "YES";
	else cout << "NO";
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

int DP(int a_pos, int b_pos, int mode) {
	if (b_pos == N) {
		if (mode == 2) return 1;
		else return 0;
	}
	int& ret = table[b_pos][mode];
	if (ret != -1) return ret;
	ret = 0;	
	if (a_pos < N - 2 && S[a_pos] == T[b_pos]) ret |= DP(a_pos + 1, b_pos + 1, mode);
	if (mode == 0 && T[b_pos] == a) ret |= DP(a_pos, b_pos + 1, mode + 1);
	else if (mode == 1 && T[b_pos] == b) ret |= DP(a_pos, b_pos + 1, mode + 1);		
	return ret;
}