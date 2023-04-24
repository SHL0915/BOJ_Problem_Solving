#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M;
ll ans = INF;
pii start;
vector <pii> pos;
int arr[1005][1005];
int mark[21];
int route[21];
int dist[1005][1005];
int path[21][21];
queue <pair<pii, int>> q;

void BFS();
void BackTracking(int k);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 1; j <= M; j++) {
			if (s[j - 1] == 'X') arr[i][j] = 0;
			else {
				arr[i][j] = 1;
				if (s[j - 1] == 'S') {
					start = { j,i };
					pos.push_back({ j,i });
				}
				else if (s[j - 1] == 'K') pos.push_back({ j,i });
			}
		}
	}
		
	for (int i = 0; i < pos.size(); i++) {
		int x = pos[i].first, y = pos[i].second;
		memset(dist, -1, sizeof(dist));
		q.push({ pos[i],0 });
		while (q.size()) BFS();
		for (int j = 0; j < pos.size(); j++) {
			path[i][j] = dist[pos[j].second][pos[j].first];
			if (path[i][j] == -1) path[i][j] = INF;
		}
	}

	int idx = -1;
	for (int i = 0; i < pos.size(); i++) if (pos[i] == start) idx = i;
	
	mark[idx] = 1;
	route[0] = idx;
	BackTracking(1);

	if (ans == INF) cout << -1;
	else cout << ans;
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
	pair<pii, int> f = q.front(); q.pop();
	int x = f.first.first;
	int y = f.first.second;
	int d = f.second;
	if (dist[y][x] != -1) return;
	dist[y][x] = d;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (arr[ny][nx] == 0) continue;
		if (dist[ny][nx] != -1) continue;
		q.push({ {nx,ny}, d + 1 });
	}
}

void BackTracking(int k) {
	if (k == 6) {
		ll sum = 0;
		for (int i = 0; i < 5; i++) sum += path[route[i]][route[i + 1]];
		ans = min(ans, sum);
		return;
	}
	else {
		for (int i = 0; i < pos.size(); i++) {
			if (mark[i]) continue;
			mark[i] = 1;
			route[k] = i;
			BackTracking(k + 1);
			mark[i] = 0;
		}
	}
}