#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, Q, flag;
vector <int> graph[300005];
set <int> child[300005];
int in_degree[300005];
int mark[300005];
int ans[100001];
vector <pii> query[300005];
queue <int> q;

void Topology();
void DFS(int node);

void solve() {
	cin >> N >> M >> Q;
	for (int i = 0; i < M; i++) {
		int s, e;
		char c;
		cin >> s >> e >> c;
		s = s * 3 + (c - 'x');
		e = e * 3 + (c - 'x' + 1) % 3;
		graph[s].push_back(e);
		in_degree[e] ++;
	}
	Topology();
	for (int i = 0; i < Q; i++) {
		int s, e;
		char c;
		cin >> s >> e >> c;
		s = s * 3 + (c - 'x');
		e = e * 3 + (c - 'x' + 1) % 3;
		query[e].push_back({ s,i });
	}
	if (flag) {
		for (int i = 0; i < Q; i++) cout << 1 << '\n';
		return;
	}
	for (int i = 3; i <= 3 * N + 2; i++) {
		if (mark[i] == 0) DFS(i);		
	}
	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void Topology() {
	for (int i = 3; i <= 3 * N + 2; i++) if (in_degree[i] == 0) q.push(i);
	for (int i = 3; i <= 3 * N + 2; i++) {
		if (q.size() == 0) {
			flag = 1;
			return;
		}
		int now = q.front();
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			if (--in_degree[graph[now][j]] == 0) q.push(graph[now][j]);
		}
	}
	return;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	child[node].insert(node);
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (child[node].size() < child[next].size()) swap(child[node], child[next]);
		for (auto j = child[next].begin(); j != child[next].end(); j++) child[node].insert(*j);
	}
	for (int i = 0; i < query[node].size(); i++) {
		pii now = query[node][i];
		int ch = now.first;
		int qnum = now.second;
		if (child[node].count(ch)) ans[qnum] = 1;
		else ans[qnum] = 0;
	}
	return;
}