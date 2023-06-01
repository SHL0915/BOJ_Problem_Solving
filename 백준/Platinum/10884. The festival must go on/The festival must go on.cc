#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, K;
vector <pii> tree[2005];
int mark[2005];

void init();
int check(ll len);
ll DP(int now, ll len);

void solve() {
	cin >> N >> M;
	init();
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	ll l = 0, r = 2000000000LL;
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;

		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout << ans << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void init() {
	for (int i = 0; i <= N; i++) tree[i].clear();
	return;
}

int check(ll len) {
	memset(mark, 0, sizeof(mark));
	mark[1] = 1;
	K = 0;
	DP(1, len);
	if (N - 1 - K >= M) return 1;
	else return 0;
	
}

ll DP(int now, ll len) {
	mark[now] = 1;
	ll ret = 0;
	priority_queue <ll> pq;

	for (auto& [next, cost] : tree[now]) {
		if (mark[next]) continue;
		pq.push(DP(next, len) + cost);
	}

	while (pq.size() >= 2) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top();

		if (a + b > len) K++;
		else {
			pq.push(a);
			break;
		}
	}

	if (pq.size() && pq.top() > len) {
		K++;
		pq.pop();
	}

	if (pq.size()) return pq.top();
	else return 0;
}