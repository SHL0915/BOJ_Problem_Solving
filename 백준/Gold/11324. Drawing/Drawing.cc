#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
map <pii, int> node;
vector <int> degree, mark;
vector <int> graph[2005];

void DFS(int node);

void solve() {
	cin >> N;
	if (N == 0) exit(0);

	degree.clear();
	degree.resize(2 * N + 5, 0);
	mark.clear();
	mark.resize(2 * N + 5, 0);
	node.clear();
	for (int i = 1; i <= 2 * N; i++) graph[i].clear();

	int id = 0;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (node.count({ a,b }) == 0) node[{a, b}] = ++id;
		if (node.count({ c,d }) == 0) node[{c, d}] = ++id;
		int aa = node[{a, b}], bb = node[{c, d}];
		graph[aa].push_back(bb);
		graph[bb].push_back(aa);
		degree[aa]++;
		degree[bb]++;
	}

	int cnt = 0;
	for (int i = 1; i <= id; i++) {
		if (mark[i] == 0) {
			cnt++;
			DFS(i);
		}
	}

	if (cnt > 1) {
		cout << "Impossible\n";
		return;
	}

	int even = 0, odd = 0;
	for (int i = 1; i <= id; i++) {
		if (degree[i] % 2) odd++;
		else even++;
	}

	if (odd == 0 || odd == 2) cout << "Possible\n";
	else cout << "Impossible\n";

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
	while (1) solve();
	return 0;
}

void DFS(int node) {
	if (mark[node]) return;
	mark[node] = 1;
	for (int next : graph[node]) DFS(next);
	return;
}