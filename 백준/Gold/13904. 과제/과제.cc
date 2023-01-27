#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[1001];

void solve() {
	cin >> N;
	priority_queue <int> pq;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, greater<>());
	int pos = 0;
	ll ans = 0;
	for (int i = 1000; i >= 1; i--) {
		while (pos < N) {
			if (arr[pos].first >= i) pq.push(arr[pos++].second);
			else break;
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
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