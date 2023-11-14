#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, K;
ll adj[105][105];
ll cost[105][105];
pii arr[105][1005];

void solve() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < K; j++) cin >> arr[i][j].first >> arr[i][j].second;
	}
	memset(adj, -1, sizeof(adj));
	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (adj[i][k] == -1 || adj[k][j] == -1) continue;
				if (adj[i][j] == -1) adj[i][j] = adj[i][k] + adj[k][j];
				else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < K; k++) {
				if (arr[i][k].first == -1 || arr[j][k].second == -1) continue;
				cost[i][j] = max(cost[i][j], arr[j][k].second - arr[i][k].first);
			}
		}
	}

	ll l = 0, r = 1000000000005LL;
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll dist[105][105];
		memset(dist, INF, sizeof(dist));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (adj[i][j] == -1) continue;
				dist[i][j] = min(dist[i][j], mid * adj[i][j] - cost[i][j]);
			}
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int flag = 0;
		for (int i = 1; i <= N; i++) {
			if (dist[i][i] <= 0) flag = 1;
		}

		if (flag) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
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
