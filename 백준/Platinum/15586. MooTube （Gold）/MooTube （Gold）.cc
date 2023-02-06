#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q, idx;
int parent[100001];
int sz[100001];
vector <pair<int, pii>> graph;
pair<pii, int> query[100001];
int ans[100001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < N - 1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		graph.push_back({ r,{p,q} });
	}
	for (int i = 0; i < Q; i++) {
		int k, v;
		cin >> k >> v;
		query[i] = { {k,v},i };
	}
	sort(graph.begin(), graph.end(), greater<>());
	sort(query, query + Q, greater<>());
	for (int i = 0; i < Q; i++) {
		int k = query[i].first.first;
		int v = query[i].first.second;
		int id = query[i].second;
		while (idx < N - 1) {
			if (graph[idx].first < k) break;
			Union(graph[idx].second.first, graph[idx].second.second);
			idx++;
		}
		ans[id] = sz[Find(v)] - 1;
	}
	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
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

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
	}
	return;
}