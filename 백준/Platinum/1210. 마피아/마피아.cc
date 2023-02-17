#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f;

int N, M, S, E;
vector <int> graph[405];
ll cap[405][405], flow[405][405];
ll parent[405], mark[405];
queue <int> bfs;

int in(int a);
int out(int a);
void find_Max(int s, int e);
void BFS();

void solve() {
	cin >> N >> M;
	cin >> S >> E;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		graph[in(i)].push_back(out(i));
		graph[out(i)].push_back(in(i));
		cap[in(i)][out(i)] = a;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[out(a)].push_back(in(b));
		graph[in(b)].push_back(out(a));
		graph[out(b)].push_back(in(a));
		graph[in(a)].push_back(out(b));
		cap[out(a)][in(b)] = INF;
		cap[out(b)][in(a)] = INF;
	}
	find_Max(in(S), out(E));
	bfs.push(in(S));
	while (bfs.size()) BFS();
	for (int i = 1; i <= N; i++) {
		if (mark[in(i)] == 1 && mark[out(i)] == 0) cout << i << " ";
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

int in(int a) {
	return a * 2 - 1;
}

int out(int a) {
	return a * 2;
}

void find_Max(int s, int e) {
	while (1) {
		queue <int> q;
		memset(parent, -1, sizeof(parent));
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
		ll val = 0x3f3f3f3f3f3f3f3fLL;
		for (int i = e; i != s; i = parent[i]) val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);
		for (int i = e; i != s; i = parent[i]) {
			flow[parent[i]][i] += val;
			flow[i][parent[i]] -= val;
		}
	}
	return;
}

void BFS() {
	int f = bfs.front();
	bfs.pop();
	if (mark[f]) return;
	mark[f] = 1;
	for (int i = 0; i < graph[f].size(); i++) {
		int now = graph[f][i];
		if (cap[f][now] - flow[f][now] > 0) bfs.push(now);
	}
	return;
}