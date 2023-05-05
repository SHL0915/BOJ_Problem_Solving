#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200005];
ll K, ans;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> K;

	for (int i = 0; i < N; i++) {
		ll now = arr[i];
		while (1) {
			if (now > K) break;
			ans += K / now;
			now *= arr[i];
		}
	}

	cout << ans;
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