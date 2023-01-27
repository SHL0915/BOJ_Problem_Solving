#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100001];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, greater<>());
	ll ans = arr[0];
	int l = 1, r = N - 1;
	while (l < r) {
		ans += arr[l] - arr[r];
		l++;
		r--;
	}
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