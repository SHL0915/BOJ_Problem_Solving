#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[50005];
int in_degree[50005];
int parent[50005];
vector <pii> query;
queue <int> q;

void Union(int a, int b);
int Find(int a);
void Topology();

void solve() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		if (c == '=') Union(a, b);
		else query.push_back({ a,b });
	}

	for (int i = 0; i < query.size(); i++) {
		int a = query[i].first, b = query[i].second;
		a = Find(a); b = Find(b);
		graph[a].push_back(b);
		in_degree[b]++;
	}

	Topology();

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

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Topology() {
	for (int i = 0; i < N; i++) if (in_degree[i] == 0) q.push(i);

	for (int i = 0; i < N; i++) {
		if (q.size() == 0) {
			cout << "inconsistent";
			return;
		}
		int now = q.front(); q.pop();
		for (int next : graph[now]) {
			if (--in_degree[next] == 0) q.push(next);
		}
	}

	cout << "consistent";
	return;
}