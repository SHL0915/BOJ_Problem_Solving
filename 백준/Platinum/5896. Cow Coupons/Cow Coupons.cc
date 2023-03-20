#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, K, M, sum;
pii arr[50001];
priority_queue <pii, vector<pii>, greater<>> pq;

void solve() {
	cin >> N >> K >> M;
	for (int i = 0; i < N; i++) cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + N);
	int cnt = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		if (cnt < K) {
			if (M >= arr[i].first) {
				pq.push({ arr[i].second - arr[i].first, i });
				M -= arr[i].first;
				cnt++; ans++;
			}
		}
		else {
			ll now = arr[i].first - arr[i].second;
			ll a = arr[i].second, b = pq.top().first + arr[i].first;

			if (a > M && b > M) continue;

			if (a < b) M -= a;
			else {
				pq.pop();
				pq.push({ arr[i].second - arr[i].first, i });
				M -= b;
			}
			ans++;
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