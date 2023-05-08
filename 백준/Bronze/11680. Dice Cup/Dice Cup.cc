#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int cnt[45];

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cnt[i + j]++;
	}
	int max_cnt = 0;
	for (int i = 1; i <= N + M; i++) max_cnt = max(max_cnt, cnt[i]);
	for (int i = 1; i <= N + M; i++) if (cnt[i] == max_cnt) cout << i << '\n';
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