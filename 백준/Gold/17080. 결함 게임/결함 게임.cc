#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int f(int k) {
	if (k == 1) return 1;
	if (((k + 1) / 2) % 2 == 1) return 1;
	else return (f(k - 1) ^ 1);
}

void solve() {
	cin >> N;
	int ans = f(N);

	if (ans) cout << 1;
	else cout << 2;

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