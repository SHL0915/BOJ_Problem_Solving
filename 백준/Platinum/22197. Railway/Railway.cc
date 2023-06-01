#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K, cnt;
vector <pii> tree[100005];
int parent[100005][21], level[100005], id[100005], arr[100005], edge_id[100005];
vector <int> ans;

void DFS(int node, int par, int lv);
void psum(int node, int par);
int LCA(int a, int b);

void solve() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back({ b,i });
		tree[b].push_back({ a,i });
	}

	DFS(1, 1, 1);

	for (int i = 0; i < M; i++) {
		int k; cin >> k;
		vector <int> v;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end(), [&](int a, int b) {
			return id[a] < id[b];
			});
		
		for (int j = 0; j < k; j++) {
			int a = v[j], b = v[(j + 1) % k];
			int lca = LCA(a, b);
			arr[lca] -= 2;
			arr[a] ++;
			arr[b] ++;
		}
	}

	psum(1, 1);

	for (int i = 2; i <= N; i++) {
		if (arr[i] >= 2 * K) ans.push_back(edge_id[i]);
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

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

void DFS(int node, int par, int lv) {
	parent[node][0] = par;
	level[node] = lv;
	id[node] = ++cnt;

	for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];

	for (auto& [next, edge] : tree[node]) {
		if (next == par) continue;
		DFS(next, node, lv + 1);
		edge_id[next] = edge;
	}

	return;
}

int LCA(int a, int b) {
	if (level[a] < level[b]) swap(a, b);

	if (level[a] != level[b]) {
		for (int i = 20; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b]) a = parent[a][i];
		}
	}

	int ret = a;
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			ret = parent[a][i];
		}
	}

	return ret;
}

void psum(int node, int par) {
	for (auto& [next, edge] : tree[node]) {
		if (next == par) continue;
		psum(next, node);
		arr[node] += arr[next];
	}

	return;
}