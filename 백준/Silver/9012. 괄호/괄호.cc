#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> s;
		stack <char> st;
		int flag = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') st.push(s[i]);
			else {
				if (st.size() && st.top() == '(') st.pop();
				else {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1 || st.size()) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}