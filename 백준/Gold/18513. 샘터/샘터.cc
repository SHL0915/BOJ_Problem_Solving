#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, K;
ll ans, cnt;
map <ll, int> mark;
queue <pii> q;

void BFS();

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		ll a; cin >> a;
		mark[a] = 1;
		q.push({ a - 1,1 });
		q.push({ a + 1, 1 });
	}

	while (q.size()) BFS();

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
	ll now = f.first;
	ll d = f.second;
	if (mark[now]) return;
	mark[now] = 1;

	ans += d;
	cnt++;
	if (cnt == K) {
		cout << ans;
		exit(0);
	}

	q.push({ now - 1, d + 1 }); q.push({ now + 1, d + 1 });
	return;
}