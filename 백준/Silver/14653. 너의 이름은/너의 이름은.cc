#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, Q;
int mark[26];
pair<int, char> query[10005];

void solve() {
	cin >> N >> K >> Q;
	int flag = 0;
	mark[0] = 1;

	for (int i = 1; i <= K; i++) {
		cin >> query[i].first >> query[i].second;

		if (i < Q) continue;
		if (i == Q) {
			for (int j = i; j >= 0; j--) {
				if (query[j].first != query[i].first) break;
				mark[query[j].second - 'A'] = 1;
			}
		}

		mark[query[i].second - 'A'] = 1;
		if (query[i].first == 0) flag = 1;
	}

	if (flag) cout << -1;
	else {
		for (int i = 0; i < N; i++) {
			if (mark[i] == 0) cout << (char)('A' + i) << ' ';
		}
	}

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