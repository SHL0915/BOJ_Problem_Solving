#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		int now = i, sum = i;
		while (now) {
			sum += now % 10;
			now /= 10;
		}
		if (sum == N) {
			cout << i;
			return;
		}
	}
	cout << 0;
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