#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, root;
vector <int> tree[200001];
int arr[200001];
int ans[200001];
set <int> s[200001];

void DFS(int node);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a == -1) {
			root = i;
			continue;
		}
		tree[a].push_back(i);
	}
	for (int i = 1; i <= N; i++) cin >> arr[i];
	DFS(root);
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
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
	int cand = 0;
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		DFS(next);
		cand = max(cand, ans[next]);
	}
	s[node].insert(arr[node]);
	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (s[node].size() < s[next].size()) swap(s[node], s[next]);
		for (auto j = s[next].begin(); j != s[next].end(); j++) s[node].insert(*j);
	}
	for (; ; cand++) if (s[node].count(cand) == 0) break;
	ans[node] = cand;
	return;
}