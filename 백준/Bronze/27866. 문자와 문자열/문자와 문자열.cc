#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string s;
int N;

void solve() {
	cin >> s >> N;
	cout << s[N - 1];
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