#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct edge { int dist, cap, rev; };
vector <edge> graph[405];

int N, M;

void add_edge(int v, int u);
int find_max(int s, int e);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) add_edge(0, i);
	for (int i = 1; i <= M; i++) add_edge(i + N, N + M + 1);
	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			add_edge(i, a + N);
		}
	}
	cout << find_max(0, N + M + 1);
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

void add_edge(int v, int u) {
	edge x;
	x.dist = u; x.cap = 1; x.rev = graph[u].size();
	graph[v].push_back(x);
	x.dist = v; x.cap = 0; x.rev = graph[v].size() - 1;
	graph[u].push_back(x);
}

int find_max(int s, int e) {
	int ret = 0;
	while (1) {
		queue <int> q;
		int v[405] = {}, pa[405] = {}, pe[405] = {};
		q.push(s);
		v[s] = 1;
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i].dist;
				int cap = graph[f][i].cap;
				if (v[now] == 0 && cap > 0) {
					q.push(now);
					pa[now] = f;
					pe[now] = i;
					v[now] = 1;
				}
			}
		}
		if (v[e] == 0) break;
		ret++;
		for (int i = e; i != s; i = pa[i]) {
			int rev = graph[pa[i]][pe[i]].rev;
			graph[pa[i]][pe[i]].cap--;
			graph[i][rev].cap++;
		}
	}
	return ret;
}