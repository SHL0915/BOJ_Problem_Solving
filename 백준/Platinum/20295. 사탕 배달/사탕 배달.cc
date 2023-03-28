#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> tree[100001];
int arr[100001];
int cnt[100001][5];
int mark[5];
int parent[100001][21], level[100001];
pii query[100001];

void pre(int node, int par, int lv);
int LCA(int a, int b);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		cnt[i][arr[i] - 1]++;
		mark[arr[i] - 1] = 1;
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	pre(1, 1, 1);
	
	cin >> M;
	cin >> query[0].first >> query[0].second;
	if (mark[query[0].second - 1]) cout << "PLAY\n";
	else cout << "CRY\n";

	for (int i = 1; i < M; i++) {
		cin >> query[i].first >> query[i].second;

		int a = query[i - 1].first, b = query[i].first, c = query[i].second - 1;
		int lca = LCA(a, b);

		if (cnt[a][c] + cnt[b][c] - 2 * cnt[lca][c] + (arr[lca] - 1 == c)) cout << "PLAY\n";
		else cout << "CRY\n";
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

void pre(int node, int par, int lv) {	
	parent[node][0] = par;
	level[node] = lv;
	for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (next == par) continue;
		for (int j = 0; j < 5; j++) cnt[next][j] += cnt[node][j];
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