#include <bits/stdc++.h>
using namespace std;

string S;
int pi[1000000];

void makePi(string s);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> S;
		if (S[0] == '.') break;
		memset(pi, 0, sizeof(pi));
		makePi(S);
		int n = S.length();
		int divider = n - pi[n - 1];
		if (n % divider != 0) cout << 1 << '\n';
		else cout << n / divider << '\n';
	}
	return 0;
}

void makePi(string s) {
	int n = s.length();
	int pos = 1, k = 0;
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
}