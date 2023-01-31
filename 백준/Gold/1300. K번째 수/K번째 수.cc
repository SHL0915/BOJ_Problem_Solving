#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

int BinarySearch(int left, int right);

void solve() {
	cin >> N >> K;
	int ans = BinarySearch(1, 1000000000);
	ll cnt = 0;
	for (int i = 1; i <= N; i++) cnt += min(ans / i, N);
	if (cnt >= K) cout << ans;
	else cout << ans + 1;
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

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 1; i <= N; i++) cnt += min(mid / i, N);
		if (cnt >= K) return BinarySearch(left, mid - 1);
		else return BinarySearch(mid + 1, right);
	}
	else return left;
}