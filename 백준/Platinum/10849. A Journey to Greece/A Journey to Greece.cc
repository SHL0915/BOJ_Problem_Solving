#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, P, M, G, T;
vector <pii> graph[20001];
pii arr[16];
int dist[20001];
int adj[16][16];
int table[16][(1 << 16)][2];
int ntable[16][(1 << 16)];

void Dijkstra(int start);
int DP(int now, int state, int ticket);
int nDP(int now, int state);

void solve() {
	cin >> N >> P >> M >> G >> T;

	int sum = 0;
	for (int i = 1; i <= P; i++) {
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	
	for (int i = 0; i <= P; i++) {
		Dijkstra(arr[i].first);
		for (int j = 0; j <= P; j++) adj[i][j] = dist[arr[j].first];
	}

	memset(table, -1, sizeof(table));
	memset(ntable, -1, sizeof(ntable));

	int t = sum + DP(0, 1, 0);
	int nt = sum + nDP(0, 1);

	if (nt <= G) cout << "possible without taxi";
	else if (t <= G) cout << "possible with taxi";
	else cout << "impossible";

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

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector <pii>, greater<>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		int now = t.second;
		int val = t.first;
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int next_val = graph[now][i].second + val;
			if (dist[next] > next_val) {
				dist[next] = next_val;
				pq.push({ next_val, next });
			}
		}
	}
	return;
}

int DP(int now, int state, int ticket) {
	if (state == (1 << (P + 1)) - 1) {
		if (ticket == 0) return min(T, adj[now][0]);
		else return adj[now][0];
	}

	int& ret = table[now][state][ticket];
	if (ret != -1) return ret;
	
	ret = INF;

	for (int i = 1; i <= P; i++) {
		if (state & (1 << i)) continue;
		if (ticket == 0) ret = min(ret, T + DP(i, state | (1 << i), 1));
		ret = min(ret, adj[now][i] + DP(i, state | (1 << i), ticket));
	}

	return ret;
}

int nDP(int now, int state) {
	if (state == (1 << (P + 1)) - 1) return adj[now][0];

	int& ret = ntable[now][state];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 1; i <= P; i++) {
		if (state & (1 << i)) continue;
		ret = min(ret, adj[now][i] + nDP(i, state | (1 << i)));
	}

	return ret;
}