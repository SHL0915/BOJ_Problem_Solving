#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int T, R, P, S, cnt, id_cnt;
vector <pii> graph[25005];
int parent[25005], id[25005];
int dist[25005];
stack <int> st;

struct cmp {
	bool operator() (pii a, pii b) {
		if (id[a.second] == id[b.second]) return a.first > b.first;
		return id[a.second] < id[b.second];
	}
};


int DFS(int node);
void Dijkstra(int start);

void solve() {
	cin >> T >> R >> P >> S;

	for (int i = 0; i < R; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 0; i < P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	for (int i = 1; i <= T; i++) if (parent[i] == 0) DFS(i);

	Dijkstra(S);

	for (int i = 1; i <= T; i++) {
		if (dist[i] == INF) cout << "NO PATH\n";
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

int DFS(int node) {
	parent[node] = ++cnt;
	int ret = cnt;
	st.push(node);

	for (pii next : graph[node]) {
		if (parent[next.first] == 0) ret = min(ret, DFS(next.first));
		else if (id[next.first] == 0) ret = min(ret, parent[next.first]);
	}

	if (ret == parent[node]) {
		id_cnt++;
		while (st.size()) {
			int t = st.top(); st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}

	return ret;
}

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector<pii>, cmp> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		int now = t.second;
		int cost = t.first;

		if (dist[now] < cost) continue;

		for (pii i : graph[now]) {
			int next = i.first;
			int next_cost = cost + i.second;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}

	return;
}