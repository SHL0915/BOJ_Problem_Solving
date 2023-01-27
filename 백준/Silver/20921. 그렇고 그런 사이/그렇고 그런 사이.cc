#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

void solve() {
	cin >> N >> K;
	int cnt = 0, now = 1;
	for (int i = N - 1; i >= 0; i--) {
		if (K < i) {
			for (int j = 0; j < i - K; j++) cout << now++ << " ";
			cout << i + 1 << " ";
			for (; now <= i; now++) cout << now << " ";
			break;
		}
		K -= i;
		cout << i + 1 << " ";
	}
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