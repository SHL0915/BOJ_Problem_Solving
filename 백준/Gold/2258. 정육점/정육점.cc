#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, M;
pii arr[100001];

bool cmp(pii a, pii b);
void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp);

	ll sum = 0;
	ll ans = INF;
	for (int i = 0; i < N; i++) {
		sum += arr[i].first;
		if (sum >= M) {
			ll val = 0;
			for (int j = i; j >= 0; j--) if (arr[j].second == arr[i].second) val += arr[j].second;
			ans = min(ans, val);
			for (int j = i + 1; j < N; j++) {
				if (arr[j].second > arr[i].second) {
					ans = min(ans, arr[j].second);
					break;
				}
			}
			cout << ans;
			return;
		}
	}

	cout << -1;
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

bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}