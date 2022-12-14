#include <bits/stdc++.h>
using namespace std;

int ans;
string s;
int pi[5000];

void init() {
	for (int i = 0; i < s.length(); i++) pi[i] = 0;
}
void makepi(string str);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		init();
		makepi(s);
		for (int i = 0; i < s.length(); i++) ans = max(ans, pi[i]);
		s.erase(s.begin());
	}
	cout << ans;
	return 0;
}

void makepi(string str) {
	int n = str.length();
	int pos = 1, k = 0;
	while (pos + k < n) {
		if (str[pos + k] == str[k]) {
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