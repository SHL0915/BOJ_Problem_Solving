#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200005];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, greater<>());

	if (N == 1) cout << arr[0];
	else if (N == 2) cout << arr[0] + arr[1] - 1;
	else {
		int ans = arr[0] - 3;
		int idx = (N - 1) / 3 + 1;
		ans += arr[idx];
		idx += (N - 2) / 3 + 1;
		ans += arr[idx];
		cout << ans;
	}

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