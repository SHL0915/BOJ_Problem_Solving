#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll L, N;
ll arr[105];
ll dist[100005];

void Dijkstra() {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector<pii>, greater<>> pq;

	dist[0] = 0;
	pq.push({ 0,0 });

	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		ll now = t.second;
		ll d = t.first;
		if (dist[now] < d) continue;
		for (int i = 0; i < N; i++) {
			ll next = now + arr[i];
			ll nd;

			if (next >= arr[N - 1]) {
				nd = d;
				next -= arr[N - 1];
			}
			else nd = d + 1;				
			
			if (dist[next] > nd) {
				dist[next] = nd;
				pq.push({ nd, next });
			}
		}
	}

	return;
}

void solve() {
	cin >> L >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	ll R = L % arr[N - 1];

	Dijkstra();

	if (dist[R] == INF) cout << "IMPOSSIBLE\n";
	else cout << dist[R] + L / arr[N - 1] << '\n';

	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1, tc = 1;
	cin >> t;
	while (t--) {
		cout << "Case #" << tc << ": ";
		solve();
		tc++;
	}
	return 0;
}