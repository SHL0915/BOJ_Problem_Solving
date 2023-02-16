#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct edge { int dist, cap, rev; };

int N, P;
vector <edge> graph[805];

void add_edge(int u, int v);
int find_Max(int s, int e);

void solve() {
	cin >> N >> P;
	for (int i = 1; i <= N; i++) add_edge(i * 2 - 1, i * 2);
	for (int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		add_edge(a * 2, b * 2 - 1);
		add_edge(b * 2, a * 2 - 1);
	}
	cout << find_Max(2, 3);
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

void add_edge(int u, int v) {
	edge x;
	x.dist = v; x.cap = 1; x.rev = graph[v].size();
	graph[u].push_back(x);
	x.dist = u; x.cap = 0; x.rev = graph[u].size() - 1;
	graph[v].push_back(x);
	return;
}

int find_Max(int s, int e) {
	int ret = 0;
	while (1) {
		int parent[805], pe[805];
		memset(parent, -1, sizeof(parent));
		memset(pe, 0, sizeof(pe));
		queue <int> q;
		q.push(s);
		while (q.size()) {
			int f = q.front(); q.pop();
			if (f == e) break;
			for (int i = 0; i < graph[f].size(); i++) {
				int now = graph[f][i].dist;
				int cap = graph[f][i].cap;
				if (parent[now] == -1 && cap > 0) {
					q.push(now);
					parent[now] = f;
					pe[now] = i;
				}
			}
		}
		if (parent[e] == -1) break;
		int val = 0x3f3f3f3f;
		for (int i = e; i != s; i = parent[i]) val = min(val, graph[parent[i]][pe[i]].cap);
		for (int i = e; i != s; i = parent[i]) {
			int rev = graph[parent[i]][pe[i]].rev;
			graph[parent[i]][pe[i]].cap -= val;
			graph[i][rev].cap += val;
		}
		ret += val;
	}
	return ret;
}