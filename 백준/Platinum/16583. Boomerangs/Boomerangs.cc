#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct boomerang {
	int a, b, c;
};

int N, M;
vector <int> graph[100005];
map <pii, int> edge;
int mark[100005];
vector <boomerang> ans;

int DFS(int node, int par);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) DFS(i, i);
	}

	cout << ans.size() << '\n';
	for (auto now : ans) cout << now.a << " " << now.b << " " << now.c << '\n';
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

int DFS(int node, int par) {
	mark[node] = 1;
	vector <int> v;
	for (int next : graph[node]) {
		if (next == par) continue;
		if (edge[{node, next}] == 1) continue;
		edge[{node, next}] = 1;
		edge[{next, node}] = 1;
		if (mark[next]) v.push_back(next);
		else {
			int res = DFS(next, node);
			if (res) continue;
			else v.push_back(next);
		}
	}

	while (v.size() >= 2) {
		int a = v.back(); v.pop_back();
		int b = v.back(); v.pop_back();
		ans.push_back({ a, node, b });
	}

	if (v.size() == 0) return 0;
	else {
		if (node == par) return 0;
		else {
			ans.push_back({ v[0], node, par });
			return 1;
		}
	}
}