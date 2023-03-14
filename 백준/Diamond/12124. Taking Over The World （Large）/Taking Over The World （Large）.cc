#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, K;
vector <int> graph[105], flow_graph[205];
int dist[105], cut[105];
vector <int> path[105];
int cap[205][205], flow[205][205], edge[205][205];
int parent[205], mark[205];
queue <int> qq;

void init();
void Dijkstra(int start);
void add_edge(int u, int v, int c);
int in(int a);
int out(int a);
int Find_Max(int s, int e);
void DFS(int node);
void BFS();

void solve() {
	cin >> N >> M >> K;
	init();

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	K--;
	cut[0] = 1;

	while (1) {
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		memset(mark, 0, sizeof(mark));

		Dijkstra(0);
				
		for (int i = 0; i < N - 1; i++) {
			if (cut[i]) add_edge(in(i), out(i), INF);
			else add_edge(in(i), out(i), 1);
		}

		DFS(N - 1);

		int m = Find_Max(out(0), in(N - 1));

		if (K < m || m == 0) {
			cout << dist[N - 1] << '\n';
			break;
		}
		else K -= m;
				
		qq.push(in(0));
		while (qq.size()) BFS();

		for (int i = 0; i < N - 1; i++) {
			if (mark[in(i)] == 1 && mark[out(i)] == 0) cut[i] = 1;
		}
	}

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

void init() {
	for (int i = 0; i < 105; i++) graph[i].clear();
	for (int i = 0; i < 205; i++) flow_graph[i].clear();
	memset(cut, 0, sizeof(cut));
	memset(edge, 0, sizeof(edge));
	return;
}

void Dijkstra(int start) {
	memset(dist, INF, sizeof(dist));
	for (int i = 0; i < 105; i++) path[i].clear();
	priority_queue <pii, vector<pii>, greater<>> pq;
	dist[start] = 1;
	pq.push({ 1, start });
	while (pq.size()) {
		pii t = pq.top(); pq.pop();
		int now = t.second, val = t.first;
		if (dist[now] < val) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			int nval = val + 1 + cut[next];
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

void add_edge(int u, int v, int c) {
	if (edge[u][v] == 0) {
		flow_graph[u].push_back(v);
		flow_graph[v].push_back(u);
		edge[u][v] = 1;
		edge[v][u] = 1;
	}
	cap[u][v] = c;
	return;
}

int in(int a) {
	return a * 2;
}

int out(int a) {
	return a * 2 + 1;
}

int Find_Max(int s, int e) {
	int ret = 0;
	while (1) {
		memset(parent, -1, sizeof(parent));
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < flow_graph[f].size(); i++) {
				int now = flow_graph[f][i];
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

void DFS(int node) {
	for (int i = 0; i < path[node].size(); i++) {
		int next = path[node][i];
		add_edge(out(next), in(node), INF);
		add_edge(out(node), in(next), INF);
		DFS(next);
	}
}

void BFS() {
	int now = qq.front(); qq.pop();
	if (mark[now]) return;
	mark[now] = 1;
	for (int i = 0; i < flow_graph[now].size(); i++) {
		int next = flow_graph[now][i];
		if (cap[now][next] - flow[now][next] > 0) qq.push(next);
	}
	return;
}