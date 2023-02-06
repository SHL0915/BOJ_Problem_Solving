#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll fact[21];

void solve() {
	cin >> N;
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;
	cout << fact[N];
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