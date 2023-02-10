#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, S, E, cnt;
vector <pii> graph[10001];
int in_degree[10001];
ll table[10001];
int mark[10001];
vector <int> path[10001];
queue <int> q;

void Topology();
void count(int node);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		in_degree[b]++;
	}
	cin >> S >> E;
	Topology();
	count(E);
	cout << table[E] << '\n' << cnt;
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

void Topology() {
	q.push(S);
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int cost = graph[now][i].second;
			if (table[next] < table[now] + cost) {
				path[next].clear();
				path[next].push_back(now);
				table[next] = table[now] + cost;
			}
			else if (table[next] == table[now] + cost) path[next].push_back(now);
			if (--in_degree[next] == 0) q.push(next);
		}
	}
	return;
}

void count(int node) {
	if (node == S) return;
	if (mark[node]) return;
	mark[node]++;
	for (int i = 0; i < path[node].size(); i++) {
		cnt++;
		count(path[node][i]);
	}
	return;
}