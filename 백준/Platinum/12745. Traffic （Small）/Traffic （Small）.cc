#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
vector <int> tree[2223];
int parent[2223][21], level[2223], arr[2223];

void pre(int node, int par, int lv);
int LCA(int a, int b);
void DFS(int node, int par);

void solve() {
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	pre(1, 1, 1);

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] ++;
		arr[b] ++;
		arr[LCA(a, b)] -= 2;
	}

	DFS(1, 0);

	pii ans = { 0x3f3f3f3f, 0x3f3f3f3f3f };
	int val = 0;

	for (int i = 1; i <= N; i++) {
		if (val < arr[i]) {
			val = arr[i];
			ans = { min(i, parent[i][0]), max(i, parent[i][0]) };
		}
		else if (val == arr[i]) ans = min(ans, make_pair(min(i, parent[i][0]), max(i, parent[i][0])));
	}

	cout << ans.first << " " << ans.second << " " << val;
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

void pre(int node, int par, int lv) {
	level[node] = lv;
	parent[node][0] = par;
	for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		pre(next, node, lv + 1);
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

void DFS(int node, int par) {
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		DFS(next, node);
		arr[node] += arr[next];
	}
}