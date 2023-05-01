#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, cnt;
pair<pii, ll> arr[1005];

int check(int x, int y);

void solve() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
	int ans_x, ans_y, flag = 0;

	int x0 = arr[0].first.first, y0 = arr[0].first.second, d0 = arr[0].second;

	if ((d0 == 0) && check(x0, y0)) {
		ans_x = x0;
		ans_y = y0;
		flag++;
	}
	
	for (int i = 0; i < d0 && flag <= 1; i++) {
		int x = x0 - d0 + i, y = y0 - i;
		if (check(x, y)) {
			ans_x = x;
			ans_y = y;
			flag++;
		}
	}

	for (int i = 0; i < d0 && flag <= 1; i++) {
		int x = x0 + i, y = y0 - d0 + i;
		if (check(x, y)) {
			ans_x = x;
			ans_y = y;
			flag++;
		}
	}

	for (int i = 0; i < d0 && flag <= 1; i++) {
		int x = x0 - i, y = y0 + d0 - i;
		if (check(x, y)) {
			ans_x = x;
			ans_y = y;
			flag++;
		}
	}

	for (int i = 0; i < d0 && flag <= 1; i++) {
		int x = x0 + d0 - i, y = y0 + i;
		if (check(x, y)) {
			ans_x = x;
			ans_y = y;
			flag++;
		}
	}

	if (flag == 0) cout << "impossible";
	else if (flag == 1) cout << ans_x << " " << ans_y;
	else cout << "uncertain";

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

int check(int x, int y) {
	for (int i = 0; i < N; i++) {
		if (abs(arr[cnt].first.first - x) + abs(arr[cnt].first.second - y) != arr[cnt].second) return 0;
		cnt++; cnt %= N;
	}

	return 1;
}