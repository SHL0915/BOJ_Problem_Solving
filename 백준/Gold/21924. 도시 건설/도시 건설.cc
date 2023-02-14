#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
ll tot, ans;
vector <pair<int, pii>> graph;
int parent[1000001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c,{a,b} });
		tot += c;
	}
	sort(graph.begin(), graph.end());
	int cnt = 0;
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		int c = graph[i].first;
		if (Find(a) == Find(b)) continue;
		ans += c;
		cnt++;
		Union(a, b);
	}
	if (cnt < N - 1) cout << -1;
	else cout << tot - ans;
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
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}