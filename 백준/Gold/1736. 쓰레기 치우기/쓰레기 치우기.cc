#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[101][101];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int last_idx = 0, curr = i, cnt = 0;
		while (curr < N) {
			for (int j = last_idx; j < M; j++) {
				if (arr[curr][j] == 1) {
					last_idx = j;
					cnt = 1;
					arr[curr][j] = 0;
				}
			}
			curr++;
		}
		ans += cnt;
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