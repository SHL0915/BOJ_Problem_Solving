#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int B[20001], pos[20001], ans[20001], mark[20001], temp[20001];

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
		pos[B[i]] = i;
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i] != 0) continue;
		for (int j = 1; j <= N; j++) {
			if (mark[j] == 1) continue;
			int flag = 0;
			int temp[20001] = { 0 };
			temp[i] = j;
			int idx = i;
			while (1) {
				if (temp[temp[idx]] != 0) {
					if (temp[temp[idx]] != pos[idx]) flag = 1;
					else flag = 0;
					break;
				}
				else temp[temp[idx]] = pos[idx];
				idx = temp[idx];
			}
			if (flag) continue;
			else {
				ans[i] = j;
				int idx = i;
				while (1) {					
					ans[ans[idx]] = pos[idx];
					mark[pos[idx]] = 1;
					idx = ans[idx];
					if (idx == i) break;
				}
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i] == 0) {
			cout << 0;
			return;
		}
	}

	cout << N << '\n';
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
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