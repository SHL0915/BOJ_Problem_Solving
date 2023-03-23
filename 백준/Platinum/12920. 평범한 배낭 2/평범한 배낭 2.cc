#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
vector <pii> arr;
ll table[10001];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll v, c, k;
		cin >> v >> c >> k;
		ll B = 1, bit = 1;
		while (B <= k) B *= 2;
		B /= 2; B--;
		
		while (B) {
			if (B & bit) {
				arr.push_back({ v * bit, c * bit });
				k -= bit;
				B -= bit;
			}
			bit <<= 1;
		}
		arr.push_back({ v * k, c * k });
	}

	ll ans = 0;

	for (int i = 0; i < arr.size(); i++) {
		for (int j = M; j >= 0; j--) {
			if (j < arr[i].first) continue;
			table[j] = max(table[j], arr[i].second + table[j - arr[i].first]);
			ans = max(ans, table[j]);
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