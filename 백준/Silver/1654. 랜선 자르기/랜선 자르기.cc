#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, N;
int arr[10001];

ll BinarySearch(ll left, ll right);

void solve() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) cin >> arr[i];
	ll ans = BinarySearch(0, (1LL << 31));
	ll cnt = 0;
	for (int i = 0; i < K; i++) cnt += arr[i] / ans;
	if (cnt >= N) cout << ans;
	else cout << ans - 1;
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

ll BinarySearch(ll left, ll right) {
	if (left < right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < K; i++) cnt += arr[i] / mid;
		if (cnt >= N) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid - 1);
	}
	else return left;
}