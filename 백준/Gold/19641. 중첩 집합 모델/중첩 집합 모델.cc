#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, cnt;
vector <int> tree[100005];
pii id[100005];

void DFS(int node, int par);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		while (1) {
			int b; cin >> b;
			if (b == -1) break;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
	}

	for (int i = 1; i <= N; i++) {
		sort(tree[i].begin(), tree[i].end());
		tree[i].erase(unique(tree[i].begin(), tree[i].end()), tree[i].end());
	}

	cin >> S;
	DFS(S, S);

	for (int i = 1; i <= N; i++) cout << i << " " << id[i].first << " " << id[i].second << '\n';
	
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

void DFS(int node, int par) {
	id[node].first = ++cnt;
	for (int next : tree[node]) {
		if (next == par) continue;
		DFS(next, node);
	}
	id[node].second = ++cnt;
}