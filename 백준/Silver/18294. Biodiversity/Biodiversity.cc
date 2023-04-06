#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
map <string, int> cnt;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		cnt[s]++;
	}
	for (auto i = cnt.begin(); i != cnt.end(); i++) {
		if ((*i).second * 2 > N) {
			cout << (*i).first;
			return;
		}
	}

	cout << "NONE";
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