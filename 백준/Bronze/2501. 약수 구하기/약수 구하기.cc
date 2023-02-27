#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

void solve() {
	cin >> N >> K;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			cnt++;
			if (cnt == K) {
				cout << i;
				return;
			}
		}
	}
	cout << 0;
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