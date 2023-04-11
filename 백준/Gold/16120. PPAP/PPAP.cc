#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
stack <char> st, check;

void solve() {
	cin >> S;
	int cnt = 0;
	for (int i = 0; i < S.length(); i++) {
		char now = S[i];

		if (now == 'P') {
			string s = "P";
			check.push(now);
			while (st.size()) {
				if (s.length() == 4) break;
				char top = st.top(); st.pop();
				check.push(top);
				s += top;
			}

			if (s.length() < 4 || s != "PAPP") {
				while (check.size()) {
					st.push(check.top());
					check.pop();
				}
			}
			else {
				while (check.size()) check.pop();
				st.push('P');
			}
		}
		else st.push(now);
	}

	if (st.size() == 1 && st.top() == 'P') cout << "PPAP";
	else cout << "NP";

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