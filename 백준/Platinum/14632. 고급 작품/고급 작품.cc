#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct stamp {
	int H, W;
	char arr[1001][1001];
};

int N, M, K, Q;
pii arr[200001];
char ans[1001][1001];
int mark[1001][1001];
stamp st[501];
pair<int, pii> query[10001];

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) ans[i][j] = '.';
	}
	for (int k = 1; k <= K; k++) {
		cin >> st[k].H >> st[k].W;
		for (int i = 0; i < st[k].H; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < st[k].W; j++) st[k].arr[i][j] = s[j];
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		query[i] = { a,{c,b} };
	}
	for (int k = Q - 1; k >= 0; k--) {
		int type = query[k].first;
		int x = query[k].second.first, y = query[k].second.second;
		for (int i = 0; i < st[type].H; i++) {
			for (int j = 0; j < st[type].W; j++) {
				if (mark[y + i][x + j]) continue;
				mark[y + i][x + j] = 1;
				ans[y + i][x + j] = st[type].arr[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cout << ans[i][j];
		cout << '\n';
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