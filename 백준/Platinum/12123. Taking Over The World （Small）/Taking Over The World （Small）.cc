#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, K;
vector <int> org[105], graph[205];
int dist[105];
vector <int> path[105];
int parent[205];
int cap[205][205], flow[205][205];

void init();
void add_edge(int a, int b, int c);
int in(int a);
int out(int a);
void Dijkstra(int start);
void DFS(int node);
int find_Max(int s, int e);

void solve() {
	init();

	for (int i = 0; i < N; i++) add_edge(in(i), out(i), 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		org[a].push_back(b);
		org[b].push_back(a);
	}

	Dijkstra(0);
	DFS(N - 1);

	int ans = dist[N - 1];

	K--; ans++;

	if (find_Max(out(0), in(N - 1)) <= K) ans++;

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
	int tc = 1;
	while (t--) {
		cout << "Case #" << tc << ": ";
		solve();
		tc++;
	}
	return 0;
}

void init() {
	cin >> N >> M >> K;
	for (int i = 0; i < 205; i++) graph[i].clear();
	for (int i = 0; i < 105; i++) {
		org[i].clear();
		path[i].clear();
	}
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
}

void add_edge(int a, int b, int c) {
	graph[a].push_back(b);
	graph[b].push_back(a);
	cap[a][b] = c;
	return;
}

int in(int a) {
	return a * 2;
}

int out(int a) {
	return a * 2 + 1;
}

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	priority_queue <pii, vector<pii>, greater<>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		int now = t.second, val = t.first;
		if (dist[now] < val) continue;
		for (int i = 0; i < org[now].size(); i++) {
			int next = org[now][i], nval = val + 1;
			if (dist[next] > nval) {
				path[next].clear();
				path[next].push_back(now);
				dist[next] = nval;
				pq.push({ nval, next });
			}
			else if (dist[next] == nval) path[next].push_back(now);
		}
	}
	return;
}

void DFS(int node) {
	for (int i = 0; i < path[node].size(); i++) {
		int next = path[node][i];
		add_edge(out(next), in(node), INF);
		DFS(next);
	}
	return;
}

int find_Max(int s, int e) {
	int ret = 0;
	while (1) {
		memset(parent, -1, sizeof(parent));
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (parent[now] == -1 && cap[f][now] - flow[f][now] > 0) {
					parent[now] = f;
					q.push(now);
				}
			}
		}
		if (parent[e] == -1) break;
		int val = INF;
		for (int i = e; i != s; i = parent[i]) val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);
		for (int i = e; i != s; i = parent[i]) {
			flow[parent[i]][i] += val;
			flow[i][parent[i]] -= val;
		}
		ret += val;
	}
	return ret;
}