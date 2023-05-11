#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
ll N;

void solve() {
	cin >> S;
	cin >> N; N--;
	ll len = S.length();

	while (1) {
		if (N < len) break;
		ll pos = len;
		while (pos <= N) pos *= 2;
		pos /= 2;
		N = (N - 1) % pos;
	}

	cout << S[N];
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