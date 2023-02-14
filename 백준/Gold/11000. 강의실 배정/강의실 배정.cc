#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
pii arr[200001];
priority_queue <int, vector<int>, greater<>> pq;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		while (pq.size()) {
			int t = pq.top();
			if (arr[i].first >= t) pq.pop();
			else break;
		}
		pq.push(arr[i].second);
		ans = max(ans, (int)pq.size());
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