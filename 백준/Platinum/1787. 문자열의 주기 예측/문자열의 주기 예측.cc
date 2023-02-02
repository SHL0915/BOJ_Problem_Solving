#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;
int pi[1000001];
int table[1000001];

void makePi(string s);
int DP(int n);

void solve() {
	cin >> N >> S;
	makePi(S);
	ll ans = 0;
	memset(table, -1, sizeof(table));	
	for (int i = N - 1; i >= 0; i--) {
		int a = DP(i);
		if ((i + 1 - a) > a) a = 0;
		ans += a;
	}
	cout << ans;	
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
				pos += k - pi[k - 1];
				k = pi[k - 1];
			}
		}
	}
	return;
}

int DP(int n) {
	int& ret = table[n];
	if (ret != -1) return ret;
	ret = 0;
	int val = pi[n];
	if (pi[n]) ret = n + 1 - pi[n] + DP(pi[n - 1]);
	return ret;
}