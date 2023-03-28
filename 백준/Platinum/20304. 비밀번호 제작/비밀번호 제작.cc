#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, ans;
int mark[(1 << 21)];
queue <pii> q;

void BFS();

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		q.push({ a,0 });
	}

	memset(mark, -1, sizeof(mark));
	while (q.size()) BFS();

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

void BFS() {
	pii f = q.front(); q.pop();
	int now = f.first;
	int d = f.second;
	if (now > N) return;
	if (mark[now] != -1) return;
	mark[now] = d;
	ans = max(ans, d);

	int bit = 1;
	while (bit <= N) {
		q.push({ now ^ bit, d + 1 });
		bit <<= 1;
	}

	return;
}