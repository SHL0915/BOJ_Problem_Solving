#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string s;

void solve() {
	cin >> N >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) cnt += s[i] - '0';
	cout << cnt;
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