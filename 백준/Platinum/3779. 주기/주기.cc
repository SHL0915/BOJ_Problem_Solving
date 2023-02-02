#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;
int pi[1000001];

void makePi(string s);

void solve() {
	int tc = 0;
	while (1) {
		tc++;
		cin >> N;
		if (N == 0) break;
		cin >> S;
		memset(pi, 0, sizeof(pi));
		makePi(S);
		cout << "Test case #" << tc << '\n';
		for (int i = 0; i < N; i++) {
			int len = i + 1, val = pi[i];
			if (val == 0 || len % (len - val)) continue;
			cout << len << " " << len / (len - val) << '\n';
		}
		cout << '\n';
	}
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