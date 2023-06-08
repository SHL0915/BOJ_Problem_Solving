#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, L, K;
pii arr[105];
vector <int> y_pos;

void solve() {
	cin >> N >> M >> L >> K;
	for (int i = 0; i < K; i++) {
		cin >> arr[i].first >> arr[i].second;
		y_pos.push_back(arr[i].second);
	}

	sort(y_pos.begin(), y_pos.end());
	y_pos.erase(unique(y_pos.begin(), y_pos.end()), y_pos.end());

	int ans = 0;
	for (int i = 0; i < K; i++) {
		int x = arr[i].first;
		for (int y : y_pos) {
			int cnt = 0;
			for (int j = 0; j < K; j++) {
				if (arr[j].first >= x && arr[j].first <= x + L && arr[j].second >= y && arr[j].second <= y + L) cnt++;
			}
			ans = max(ans, cnt);
		}
	}

	cout << K - ans;
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