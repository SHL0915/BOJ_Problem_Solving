#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
ll K;
ll pi[500001];

void makePi(string s);

void solve() {
	cin >> S >> K;
	ll len = S.length();
	makePi(S);
	cout << len * K - (K - 1) * pi[len - 1];
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
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}