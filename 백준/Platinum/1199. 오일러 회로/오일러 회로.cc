#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int degree[1005];
pii seg[1005][2005];

void DFS(int node);
void update(int idx, int pos, pii val);
pii query(int idx, int l, int r);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a; cin >> a;
			degree[i] += a;
			update(i, j, { a, j });
		}
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2) {
			cout << -1;
			return;
		}
	}

	DFS(1);

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

void DFS(int node) {
	while (1) {
		pii now = query(node, 1, N + 1);
		if (now.first == 0) break;
		update(node, now.second, { now.first - 1, now.second });
		update(now.second, node, { now.first - 1, node });
		DFS(now.second);
	}
	cout << node << " ";
	return;
}

void update(int idx, int pos, pii val) {
	for (seg[idx][pos += N] = val; pos > 0; pos >>= 1) seg[idx][pos >> 1] = max(seg[idx][pos], seg[idx][pos ^ 1]);
	return;
}

pii query(int idx, int l, int r) {
	pii ret = { 0, 0 };
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, seg[idx][l++]);
		if (r & 1) ret = max(ret, seg[idx][--r]);
	}
	return ret;
}