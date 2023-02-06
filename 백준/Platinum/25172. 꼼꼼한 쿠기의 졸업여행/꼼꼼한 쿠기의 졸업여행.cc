#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <int> graph[200001];
int mark[200001];
int parent[200001];
int sz[200001];
int query[200001];
vector <int> ans;

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sz[i] = 1;
		cin >> query[i];
	}
	ans.push_back(0);
	ans.push_back(1);
	mark[query[N]] = 1;
	for (int i = N - 1; i >= 1; i--) {
		int now = query[i], cnt = N - i + 1;
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			if (mark[next] == 1) Union(now, next);
		}
		if (sz[Find(now)] == cnt) ans.push_back(1);
		else ans.push_back(0);
		mark[now] = 1;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i]) cout << "CONNECT\n";
		else cout << "DISCONNECT\n";
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

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
	}
}