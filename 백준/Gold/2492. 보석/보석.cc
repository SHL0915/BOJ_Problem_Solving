#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, T, K;
pii arr[105];
vector <int> pos;

void solve() {
	cin >> N >> M >> T >> K;

	for (int i = 0; i < T; i++) {
		cin >> arr[i].first >> arr[i].second;
		pos.push_back(arr[i].second);
	}

	int ans = 0, ans_x = 0, ans_y = 0;
	for (int i = 0; i < T; i++) {
		int x = arr[i].first;
		for (int y : pos) {
			int cnt = 0;
			for (int j = 0; j < T; j++) {
				if (arr[j].first >= x && arr[j].first <= x + K && arr[j].second >= y && arr[j].second <= y + K) cnt++;
			}
			if (cnt > ans) {
				ans_x = min(x, N - K);
				ans_y = min(y, M - K);
				ans = cnt;
			}
		}
	}

	cout << ans_x << " " << ans_y + K << '\n';
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