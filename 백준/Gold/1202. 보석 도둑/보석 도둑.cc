#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
pii arr[300001];
int bag[300001];
priority_queue <int> pq;

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	for (int i = 0; i < K; i++) cin >> bag[i];
	sort(bag, bag + K);
	int idx = 0;
	ll ans = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N) {
			if (arr[idx].first <= bag[i]) {
				pq.push(arr[idx].second);
				idx++;
			}
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