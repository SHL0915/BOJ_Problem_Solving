#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int parent[1055];
vector <int> graph[1055];
vector <pair<int, pii>> edge;

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int a; cin >> a;
			edge.push_back({ a, {i,j} });
		}
	}

	sort(edge.begin(), edge.end());
	
	int cnt = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (cnt == N - 1) break;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		graph[a].push_back(b);
		graph[b].push_back(a);
		cnt++;
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
		cout << graph[i].size() << " ";
		for (int a : graph[i]) cout << a << " ";
		cout << '\n';
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

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}

int Find(int a) {
	if (parent[a] == a) return parent[a];
	else return parent[a] = Find(parent[a]);
}