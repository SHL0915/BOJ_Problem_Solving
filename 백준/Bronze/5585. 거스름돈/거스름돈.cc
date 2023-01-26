#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	N = 1000 - N;
	int ans = 0;
	ans += N / 500;
	N %= 500;
	ans += N / 100;
	N %= 100;
	ans += N / 50;
	N %= 50;
	ans += N / 10;
	N %= 10;
	ans += N / 5;
	N %= 5;
	ans += N / 1;
	N %= 1;
	cout << ans;
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