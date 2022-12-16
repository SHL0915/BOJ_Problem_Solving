#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(1);
	string s;
	double ans = 0;
	cin >> s;
	switch (s[0]) {
	case 'A': ans += 4; break;
	case 'B': ans += 3; break;
	case 'C': ans += 2; break;
	case 'D': ans += 1; break;
	}
	if (ans == 0) cout << ans;
	else {
		switch (s[1]) {
		case '+': ans += 0.3; break;
		case '0': break;
		case '-': ans -= 0.3; break;
		}
		cout << ans;
	}
	return 0;
}