#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int arr[50001];

ll BinarySearch(ll left, ll right);

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	ll ans = BinarySearch(0, 1000000005L);

	int cnt = 1, prev = arr[0];

	for (int i = 0; i < N; i++) {
		if (arr[i] > prev + 2 * ans) {
			cnt++;
			prev = arr[i];
		}
	}

	if (cnt > K) ans++;

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

ll BinarySearch(ll left, ll right) {
	if (left < right) {
		ll mid = (left + right) / 2;
		int cnt = 1, prev = arr[0];

		for (int i = 0; i < N; i++) {
			if (arr[i] > prev + 2 * mid) {
				cnt++;
				prev = arr[i];
			}
		}

		if (cnt > K) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid - 1);
	}
	else return left;
}