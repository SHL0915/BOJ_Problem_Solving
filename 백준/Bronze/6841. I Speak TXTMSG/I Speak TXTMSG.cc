#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

map <string, string> m;

void solve() {
	m["CU"] = "see you";
	m[":-)"] = "I’m happy";
	m[":-("] = "I’m unhappy";
	m[";-)"] = "wink";
	m[":-P"] = "stick out my tongue";
	m["(~.~)"] = "sleepy";
	m["TA"] = "totally awesome";
	m["CCC"] = "Canadian Computing Competition";
	m["CUZ"] = "because";
	m["TY"] = "thank-you";
	m["YW"] = "you’re welcome";
	m["TTYL"] = "talk to you later";

	while (1) {
		string S; cin >> S;
		if (m.count(S)) cout << m[S] << '\n';
		else cout << S << '\n';
		if (S == "TTYL") break;
	}

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}