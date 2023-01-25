#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, root = -1, len, ans;
vector <int> graph[100001];

pii DFS(int node, int par);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	root = DFS(1, -1).second;
	ans = DFS(root, -1).first;	
	if (len) cout << ans + len;
	else cout << 0;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

pii DFS(int node, int par) {
	vector <pii> sub;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (next == par) continue;
		sub.push_back(DFS(next, node));
	}
	if (sub.size() == 0) return { 1,node };
	else {
		sort(sub.begin(), sub.end(), greater<>());
		if (root != -1 && sub.size() >= 2) len = max(len, sub[1].first);
		return { sub[0].first + 1, sub[0].second };
	}
}