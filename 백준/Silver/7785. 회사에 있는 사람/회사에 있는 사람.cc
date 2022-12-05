#include <bits/stdc++.h>
using namespace std;

int N;
set <string> s;
string enter = "enter";
string leave = "leave";
vector <string> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--) {
		string name, action;
		cin >> name >> action;
		if (action == enter) s.insert(name);
		else s.erase(name);
	}
	for (auto i = s.begin(); i != s.end(); i++) ans.push_back(*i);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
	return 0;
}