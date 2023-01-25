#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, len, root = -1;
vector <int> graph[200005];
int ans[200005];

pii DFS(int node, int par, int level);

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	root = DFS(1, -1, 0).second;
	len = DFS(root, -1, 0).first - 1;
	for (int i = N; i >= 1; i--) {
		if (i % 2 == 0) ans[i] = max(ans[i], ans[i + 2]);
	}	
	for (int i = 1; i <= N; i++) {
		int output;
		if (len >= i) output = 2;
		else output = 1;
		if (i % 2) cout << output << '\n';
		else cout << max(output, ans[i]) << '\n';
	}	
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

pii DFS(int node, int par, int level) {
	vector <pii> v;
	v.push_back({ 1,node });
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (next == par) continue;
		pii dfs = DFS(next, node, level + 1);
		v.push_back({ dfs.first + 1, dfs.second });
	}
	sort(v.begin(), v.end(), greater<>());
	pii ret = v[0];
	if (root != -1) {		
		v.push_back({ level + 1,0 });
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			int now = v[i].first - 1, cnt = v.size() - i;
			if (now < 1) continue;
			if (now * 2 > N) break;
			ans[now * 2] = max(ans[now * 2], cnt);
		}
	}
	return ret;
}