#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B, E, P, flag;
vector <int> graph[5005], rgraph[5005];
set <int> sz[5005], rsz[5005];
int in_degree[5005], rin_degree[5005];

void Topology();

void solve() {
	cin >> A >> B >> E >> P;
	for (int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		in_degree[b] ++;
		rgraph[b].push_back(a);
		rin_degree[a]++;
	}

	Topology();

	int ans = 0;
	for (int i = 0; i < E; i++) {
		if (rsz[i].size() > E - A) ans++;
	}
	cout << ans << '\n';

	ans = 0;
	for (int i = 0; i < E; i++) {
		if (rsz[i].size() > E - B) ans++;
	}
	cout << ans << '\n';

	ans = 0;
	for (int i = 0; i < E; i++) {
		if (sz[i].size() > B) ans++;
	}
	cout << ans;

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

void Topology() {
	queue <int> q;
	for (int i = 0; i < E; i++) {
		if (in_degree[i] == 0) {
			sz[i].insert(i);
			q.push(i);
		}
	}

	for (int i = 0; i < E; i++) {
		int now = q.front(); q.pop();

		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			for (auto k = sz[now].begin(); k != sz[now].end(); k++) sz[next].insert(*k);
			if (--in_degree[next] == 0) {
				sz[next].insert(next);
				q.push(next);
			}
		}
	}

	for (int i = 0; i < E; i++) {
		if (rin_degree[i] == 0) {
			rsz[i].insert(i);
			q.push(i);
		}
	}

	for (int i = 0; i < E; i++) {
		int now = q.front(); q.pop();

		for (int j = 0; j < rgraph[now].size(); j++) {
			int next = rgraph[now][j];
			for (auto k = rsz[now].begin(); k != rsz[now].end(); k++) rsz[next].insert(*k);
			if (--rin_degree[next] == 0) {
				rsz[next].insert(next);
				q.push(next);
			}
		}
	}

	return;
}