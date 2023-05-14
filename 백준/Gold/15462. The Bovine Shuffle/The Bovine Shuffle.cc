#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector <int> graph[100005];
int mark[100005];
int isCycle[100005];

void DFS(int node, int root);
void FindCycle(int node);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		graph[i].push_back(a);
	}

	for (int i = 1; i <= N; i++) if (mark[i] == 0) DFS(i, i);

	int cnt = 0;
	for (int i = 1; i <= N; i++) cnt += isCycle[i];

	cout << cnt;
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

void DFS(int node, int root) {
	if (mark[node]) {
		if (mark[node] == root) {
			FindCycle(node);
			return;
		}
		else return;
	}
	mark[node] = root;
	DFS(graph[node][0], root);
	return;
}

void FindCycle(int node) {
	if (isCycle[node]) return;
	isCycle[node] = 1;
	FindCycle(graph[node][0]);
	return;
}
