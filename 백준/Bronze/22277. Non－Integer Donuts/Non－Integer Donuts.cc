#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	string s;
	cin >> s;
	ll now = 0;
	int flag = 0;
	for (int i = 0; i < s.length(); i++) {
		if (flag == 1) {
			now *= 10;
			now += s[i] - '0';
		}
		if (s[i] == '.') flag = 1;		
	}
	
	int ans = 0;

	for (int i = 0; i < N; i++) {
		ll add = 0;
		flag = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (flag == 1) {
				add *= 10;
				add += s[j] - '0';
			}
			if (s[j] == '.') flag = 1;
		}
		now += add;
		if (now % 100 != 0) ans++;
	}

	cout << ans;
	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
