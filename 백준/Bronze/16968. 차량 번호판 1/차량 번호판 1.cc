#include <bits/stdc++.h>
using namespace std;

string s;
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	if (s[0] == 'd') ans = 10;
	if (s[0] == 'c') ans = 26;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'c') {
			if (s[i - 1] == 'c') ans *= 25;
			else ans *= 26;
		}
		else {
			if (s[i - 1] == 'd') ans *= 9;
			else ans *= 10;
		}
	}
	cout << ans;
	return 0;
}