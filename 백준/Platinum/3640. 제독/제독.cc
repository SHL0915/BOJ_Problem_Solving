#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
vector <int> graph[2005];
ll cap[2005][2005], flow[2005][2005], cost[2005][2005];

ll MCMF(int s, int e);
int in(int node);
int out(int node);
void add_edge(int u, int v, ll ca, ll co);

void solve() {
	for (int i = 0; i < 2005; i++) graph[i].clear();
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	memset(cost, 0, sizeof(cost));
	
	add_edge(in(1), out(1), 2, 0);
	add_edge(in(N), out(N), 2, 0);

	for (int i = 2; i <= N - 1; i++) add_edge(in(i), out(i), 1, 0);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(out(a), in(b), 1, c);
	}

	cout << MCMF(in(1), out(N)) << '\n';
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (cin >> N >> M) solve();
	return 0;
}

ll MCMF(int s, int e) {
	ll ret = 0;
	while (1) {
		int par[2005], dist[2005], mark[2005];
		memset(par, -1, sizeof(par));
		memset(dist, INF, sizeof(dist));
		memset(mark, 0, sizeof(mark));
		queue <int> q;
		q.push(s);
		dist[s] = 0;
		mark[s] = 1;
		while (q.size()) {
			int f = q.front(); q.pop();
			mark[f] = 0;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i];
				if (cap[f][now] - flow[f][now] > 0 && dist[now] > dist[f] + cost[f][now]) {
					dist[now] = dist[f] + cost[f][now];
					par[now] = f;
					if (mark[now] == 0) {
						mark[now] = 1;
						q.push(now);
					}
				}
			}
		}
		if (par[e] == -1) break;
		ll val = INF;
		for (int i = e; i != s; i = par[i]) val = min(val, cap[par[i]][i] - flow[par[i]][i]);
		for (int i = e; i != s; i = par[i]) {
			ret += val * cost[par[i]][i];
			flow[par[i]][i] += val;
			flow[i][par[i]] -= val;
		}
	}
	return ret;
}

int in(int node) {
	return node * 2 - 1;
}

int out(int node) {
	return node * 2;
}

void add_edge(int u, int v, ll ca, ll co) {
	graph[u].push_back(v);
	graph[v].push_back(u);
	cap[u][v] = ca;
	cost[u][v] = co;
	cost[v][u] = -co;
}