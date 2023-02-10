#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, W;
vector <int> graph[1001];
int in_degree[1001];
ll arr[1001];
ll table[1001];
queue <int> q;

void Topology();

void solve() {
	cin >> N >> K;
	memset(in_degree, 0, sizeof(in_degree));
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		graph[i].clear();
	}
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		in_degree[b]++;
	}
	Topology();
	cin >> W;
	cout << table[W] << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void Topology() {
	memset(table, 0, sizeof(table));
	for (int i = 1; i <= N; i++) if (in_degree[i] == 0) q.push(i);
	for (int i = 1; i <= N; i++) {		
		int now = q.front();
		q.pop();
		table[now] += arr[now];
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			table[next] = max(table[next], table[now]);
			if (--in_degree[next] == 0) q.push(next);
		}
	}
	return;
}