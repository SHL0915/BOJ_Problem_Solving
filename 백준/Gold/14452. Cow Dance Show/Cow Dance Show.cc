#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, T;
int arr[10005];

void solve() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int l = 0, r = 100005;
	int ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;

		int now = 0;
		priority_queue <int, vector <int>, greater<>> pq;
		for (int i = 0; i < N; i++) {
			if (i < mid) pq.push(arr[i]);
			else {
				now = pq.top();
				pq.pop();
				pq.push(now + arr[i]);
			}
		}

		while (pq.size()) {
			now = pq.top();
			pq.pop();
		}

		if (now <= T) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
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