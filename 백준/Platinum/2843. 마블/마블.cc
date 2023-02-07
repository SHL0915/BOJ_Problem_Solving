#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q, cnt = 1;
vector <int> graph[300001];
pii query[300001];
int parent[300001];
int mark[300001];
int del[300001];

void DFS(int node, int check);
int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		int a; cin >> a;
		if (a) graph[i].push_back(a);		
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		query[i] = { a,b };
		if (a == 2) del[b] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (mark[i] == 0) DFS(i, cnt++);
	}
	vector <int> ans;
	for (int i = Q - 1; i >= 0; i--) {
		int a = query[i].first, b = query[i].second;
		if (a == 1) ans.push_back(Find(b));		
		else {
			if (Find(b) == Find(graph[b][0])) Union(graph[b][0], 0);
			Union(b, graph[b][0]);
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i]) cout << ans[i] << '\n';
		else cout << "CIKLUS\n";
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

void DFS(int node, int check) {
	if (mark[node] == check) {
		Union(node, 0);
		return;
	}
	mark[node] = check;
	for (int i = 0; i < graph[node].size(); i++) {
		if (del[node]) continue;
		DFS(graph[node][i], check);
		Union(node, graph[node][i]);
	}
	return;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	parent[a] = b;
	return;
}