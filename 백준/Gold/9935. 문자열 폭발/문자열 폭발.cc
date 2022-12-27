#include <bits/stdc++.h>
using namespace std;

string s, explode;
deque <char> dq;
stack <char> st;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> explode;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == explode.back()) {
			st.push(s[i]);
			for (int j = explode.size() - 2; j >= 0; j--) {
				if (dq.size() == 0 || dq.back() != explode[j]) {
					while (st.size()) {
						dq.push_back(st.top());
						st.pop();
					}
					break;
				}
				st.push(dq.back());
				dq.pop_back();
			}
			while (st.size()) st.pop();
		}
		else dq.push_back(s[i]);
	}
	if (dq.size() == 0) cout << "FRULA";
	else for (int i = 0; i < dq.size(); i++) cout << dq[i];	
	return 0;
}