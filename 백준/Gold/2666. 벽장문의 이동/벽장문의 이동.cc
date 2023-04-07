#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, a, b, K;
int arr[21];
int ans = 0x3f3f3f3f;

void BackTracking(int l, int r, int k, int val);

void solve() {
	cin >> N >> a >> b;
	cin >> K;
	for (int i = 0; i < K; i++) cin >> arr[i];

	if (a > b) swap(a, b);
	BackTracking(a, b, 0, 0);

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

void BackTracking(int l, int r, int k, int val) {
	if (k == K) {
		ans = min(ans, val);
		return;
	}
	else {
		int now = arr[k];
		if (now == l) BackTracking(l, r, k + 1, val);
		else if (now == r) BackTracking(l, r, k + 1, val);
		else if (now > l && now < r) {
			BackTracking(now, r, k + 1, val + now - l);
			BackTracking(l, now, k + 1, val + r - now);
		}
		else if (now < l) BackTracking(now, r, k, val + l - now);
		else BackTracking(l, now, k, val + now - r);
	}
	return;
}