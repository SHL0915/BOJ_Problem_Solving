#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

ll strtoll(string s);
ll GCD(ll a, ll b);

void solve() {
	cin >> S;
	string a = "", b = "";
	ll A, B, flag = 0;
	for (int i = 0; i < S.length(); i++) {
		if (flag) b += S[i];
		else {
			if (S[i] == ':') flag = 1;
			else a += S[i];
		}
	}
	A = strtoll(a);
	B = strtoll(b);
	cout << A / GCD(A, B) << ":" << B / GCD(A, B) << '\n';
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

ll strtoll(string s) {
	ll ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

ll GCD(ll a, ll b) {
	if (a > b) {
		if (a % b) return GCD(a % b, b);
		else return b;
	}
	else {
		if (b % a) return GCD(b % a, a);
		else return a;
	}
}