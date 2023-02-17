#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;
int pi[10001];
int len[501];
bool mark[501][100001];
int table[100001];

void makePi(string s);
void kmp(string s, string cmp, int idx);
int DP(int pos);

void solve() {
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		len[i] = s.length();
		memset(pi, 0, sizeof(pi));
		makePi(s);
		kmp(S, s, i);
	}
	memset(table, -1, sizeof(table));
	cout << DP(0);
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

void makePi(string s) {
	int n = s.length(), pos = 1, k = 0;
	while (pos + k < n) {
		if (s[pos + k] == s[k]) {
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}

void kmp(string s, string cmp, int idx) {
	int n = s.length(), m = cmp.length(), pos = 0, k = 0;
	while (pos + m <= n) {
		if (k < m && s[pos + k] == cmp[k]) {
			k++;
			if (k == m) mark[idx][pos] = true;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}

int DP(int pos) {
	if (pos == S.length()) return 0;
	int & ret = table[pos];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, DP(pos + 1));
	for (int i = 0; i < N; i++) if (mark[i][pos]) ret = max(ret, len[i] + DP(pos + len[i]));
	return ret;
}