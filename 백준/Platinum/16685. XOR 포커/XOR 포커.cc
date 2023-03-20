#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100001];
ll basis[64];

void solve() {
	cin >> N;
	ll f; cin >> f;
	for (int i = 1; i < N; i++) {
		ll a; cin >> a;
		arr[i] = a ^ f;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 63; j >= 0; j--) {
			if (arr[i] & (1LL << j)) {
				if (basis[j] == 0) {
					basis[j] = arr[i];
					break;
				}
				else arr[i] ^= basis[j];
			}
		}
	}

	ll ans = 0;
	for (int i = 63; i >= 0; i--) ans = max(ans, ans ^ basis[i]);

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