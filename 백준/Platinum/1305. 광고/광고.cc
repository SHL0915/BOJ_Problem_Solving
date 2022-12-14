#include <bits/stdc++.h>
using namespace std;

int L, ans = 1;
int pi[1000000];
string str;

void makepi(string s);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> L;
	cin >> str;
	makepi(str);
	cout << L - pi[L - 1];
	return 0;
}

void makepi(string s) {
	int n = s.length();
	int pos = 1, k = 0;
	while (pos + k < n) {
		if (s[k] == s[pos + k]) {
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