#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, B;
int arr[100005];

void solve() {
	cin >> N >> K >> B;
	for (int i = 0; i < B; i++) {
		int a; cin >> a;
		arr[a]++;
	}
	for (int i = 1; i <= N; i++) arr[i] += arr[i - 1];

	int ans = 0x3f3f3f3f;
	for (int i = K; i <= N; i++) ans = min(ans, arr[i] - arr[i - K]);

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