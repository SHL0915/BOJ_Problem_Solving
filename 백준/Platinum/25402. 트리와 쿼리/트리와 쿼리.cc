#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
vector <int> graph[250005];
int parent[250005];
ll sz[250005];
int mark[250005];
set <int> s;

void Union(int a, int b);
int Find(int a);
void DFS(int node, int par);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			s.insert(a);
		}

		for (auto j = s.begin(); j != s.end(); j++) {
			if (mark[*j]) continue;
			DFS(*j, *j);
		}

		ll ans = 0;

		for (auto j = s.begin(); j != s.end(); j++) {
			if (Find(*j) == *j) {
				ans += (sz[*j]) * (sz[*j] - 1) / 2;
			}
		}

		for (auto j = s.begin(); j != s.end(); j++) {
			parent[*j] = *j; sz[*j] = 1; mark[*j] = 0;
		}

		cout << ans << '\n';
		s.clear();
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

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	parent[a] = b;
	sz[b] += sz[a];
	return;
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void DFS(int node, int par) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (s.count(next) == 0) continue;
		if (next == par) continue;
		Union(node, next);
		DFS(next, node);
	}

	return;
}