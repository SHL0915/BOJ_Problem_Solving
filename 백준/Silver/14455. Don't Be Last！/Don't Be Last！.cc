#include <bits/stdc++.h>
using namespace std;

int N, cnt;
map <string, int> m;
set <int> s;
string ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	m["Bessie"] = 0;
	m["Elsie"] = 0;
	m["Daisy"] = 0;
	m["Gertie"] = 0;
	m["Annabelle"] = 0;
	m["Maggie"] = 0;
	m["Henrietta"] = 0;
	for (int i = 0; i < N; i++) {
		string name;
		int val;
		cin >> name >> val;
		m[name] += val;
	}
	for (auto i = m.begin(); i != m.end(); i++) s.insert((*i).second);
	s.erase(*(s.begin()));
	if (s.size() == 0) {
		cout << "Tie\n";
		return 0;
	}
	int val = *(s.begin());
	for (auto i = m.begin(); i != m.end(); i++) {
		if ((*i).second == val) {
			ans = (*i).first;
			cnt++;
		}
	}
	if (cnt >= 2) cout << "Tie\n";
	else cout << ans << '\n';
	return 0;
}