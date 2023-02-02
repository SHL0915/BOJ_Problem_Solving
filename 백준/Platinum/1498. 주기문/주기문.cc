#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int pi[1000001];

void makePi(string s);

void solve() {
	cin >> S;
	makePi(S);
	int n = S.length();
	for (int i = 1; i < n; i++) {
		int val = pi[i];
		int len = i + 1;
		if (val == 0 || len % (len - val)) continue;
		else cout << len << " " << len / (len - val) << '\n';
	}
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
}