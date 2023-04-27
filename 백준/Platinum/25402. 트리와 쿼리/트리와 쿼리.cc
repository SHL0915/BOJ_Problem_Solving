#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
vector <int> graph[250005];
int parent[250005];
ll sz[250005];
int mark[250005];

void Union(int a, int b);
int Find(int a);
void DFS(int node);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
		mark[i] = 1;
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
		vector <int> arr;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			arr.push_back(a);
			mark[a] = 0;
			parent[a] = a;
			sz[a] = 1;
		}

		ll ans = 0;

		for (int j = 0; j < k; j++) {
			if (mark[arr[j]]) continue;
			DFS(arr[j]);
			ans += sz[Find(arr[j])] * (sz[Find(arr[j])] - 1) / 2;
		}

		cout << ans << '\n';
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

void DFS(int node) {
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (mark[next]) continue;
		Union(node, next);
		DFS(next);
	}
	return;
}