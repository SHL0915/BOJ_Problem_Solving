#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
vector <pii> graph[501];
ll dist[501], mark[501], cycle[501];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	memset(dist, INF, sizeof(dist));
	
	queue <int> q;
	dist[1] = 0;
	mark[1] = 1;
	cycle[1] = 1;

	q.push(1);
	while (q.size()) {
		int now = q.front(); q.pop();

		mark[now] = 0;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int val = graph[now][i].second;

			if (dist[next] > dist[now] + val) {
				dist[next] = dist[now] + val;
				if (mark[next] == 0) {
					cycle[next]++;
					
					if (cycle[next] >= N) {
						cout << -1;
						return;
					}

					q.push(next);
					mark[next] = 1;
				}
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
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