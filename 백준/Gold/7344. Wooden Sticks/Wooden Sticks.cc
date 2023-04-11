#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[5001];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);

	deque <int> ans;
	for (int i = 0; i < N; i++) {
		int now = arr[i].second;

		if (ans.size() == 0 || now < ans[0]) ans.push_front(now);
		else {
			int idx = upper_bound(ans.begin(), ans.end(), now) - ans.begin();
			ans[idx - 1] = now;
		}
	}

	cout << ans.size() << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}