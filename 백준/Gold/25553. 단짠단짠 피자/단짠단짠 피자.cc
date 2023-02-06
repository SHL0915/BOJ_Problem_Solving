#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, Q, K;
ll val[4] = { -INF, -INF, -INF, -INF };
ll idx[4];
ll sum[2];
ll arr[400001];
ll psum[400001];

bool cmp(pii a, pii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

void solve() {
	cin >> N >> Q >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i + N] = arr[i];
	}
	for (int i = 1; i <= 2 * N; i++) psum[i] = psum[i - 1] + arr[i];
	if (N % 2 == 0) {
		for (int i = 1; i <= N; i++) {
			ll now = psum[i + K - 1] - psum[i - 1];
			if (i % 2) {
				if (now > val[1]) {
					val[1] = now;
					idx[1] = i;
				}
			}
			else {
				if (now > val[0]) {
					val[0] = now;
					idx[0] = i;
				}
			}
		}

		for (int i = 0; i < Q; i++) {
			int t, x;
			cin >> t;
			if (t == 1) {
				cin >> x;
				sum[1] += x;
			}
			else if (t == 2) {
				cin >> x;
				sum[0] += x;
			}
			else {
				ll a = val[0] + sum[0] * (1 + (K - 1) / 2) + sum[1] * (K / 2);
				ll b = val[1] + sum[1] * (1 + (K - 1) / 2) + sum[0] * (K / 2);
				if (a == b) cout << min(idx[0], idx[1]) << " " << a << '\n';
				else if (a > b) cout << idx[0] << " " << a << '\n';
				else cout << idx[1] << " " << b << '\n';
			}			
		}
	}
	else {
		for (int i = 1; i <= N - K + 1; i++) {
			ll now = psum[i + K - 1] - psum[i - 1];
			if (i % 2) {
				if (now > val[1]) {
					val[1] = now;
					idx[1] = i;
				}
			}
			else {
				if (now > val[0]) {
					val[0] = now;
					idx[0] = i;
				}
			}
		}
		for (int i = N - K + 2; i <= N; i++) {
			ll now = psum[i + K - 1] - psum[i - 1];
			if (i % 2) {
				if (now > val[3]) {
					val[3] = now;
					idx[3] = i;
				}
			}
			else {
				if (now > val[2]) {
					val[2] = now;
					idx[2] = i;
				}
			}
		}
		for (int i = 0; i < Q; i++) {
			int t, x;
			cin >> t;
			if (t == 1) {
				cin >> x;
				sum[1] += x;
			}
			else if (t == 2) {
				cin >> x;
				sum[0] += x;
			}
			else {
				vector <pii> ans;
				ll a = val[0] + sum[0] * (1 + (K - 1) / 2) + sum[1] * (K / 2);
				ll b = val[1] + sum[1] * (1 + (K - 1) / 2) + sum[0] * (K / 2);
				ll left = N - idx[2] + 1, right = K - left;
				ll c = val[2] + sum[0] * (1 + (left - 1) / 2) + sum[1] * (left / 2) + sum[1] * (1 + (right - 1) / 2) + sum[0] * (right / 2);
				left = N - idx[3] + 1;
				right = K - left;
				ll d = val[3] + sum[1] * (1 + (left - 1) / 2) + sum[0] * (left / 2) + sum[1] * (1 + (right - 1) / 2) + sum[0] * (right / 2);
				ans.push_back({ a, idx[0] });
				ans.push_back({ b, idx[1] });
				ans.push_back({ c, idx[2] });
				ans.push_back({ d, idx[3] });
				sort(ans.begin(), ans.end(), cmp);
				cout << ans[0].second << " " << ans[0].first << '\n';
			}
		}


	}

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