#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K, S, cnt;
vector <int> org[300005];
vector <int> tree[600005];
int in_degree[600005], parent[600005];
pii id[600005];

void DFS(int node);

void solve() {
	cin >> N >> M >> K >> S;
	if (S > K) {
		cout << 0;
		return;
	}

	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			org[i].push_back(a);
			parent[a] = i;
		}
	}

	for (int i = 1; i <= N + S; i++) {
		int k; cin >> k;
		if (k > M) {
			cout << 0;
			return;
		}
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			tree[i].push_back(a);
			in_degree[a]++;
		}
	}

	int root = -1;

	for (int i = 1; i <= N + S; i++) {
		if (in_degree[i] == 0) root = i;
	}

	DFS(root);

	for (int i = 1; i <= N; i++) {
		if (parent[i] == 0) continue;
		int a = i, b = parent[i];

		if (id[b].first <= id[a].first && id[b].second >= id[a].second) continue;
		else {
			cout << 0;
			return;
		}
	}

	cout << 1;
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

void DFS(int node) {
	id[node].first = ++cnt;
	for (int next : tree[node]) DFS(next);
	id[node].second = cnt;
	return;
}