#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector <pair<int, pii>> edge;
int parent[50001];

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N >> M >> K;
	ll tot = 0;
	
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c,{a,b} });
		if (i < K) tot += c;
	}

	sort(edge.begin(), edge.end());
	ll cnt = 0, cost = 0;
	for (int i = 0; i < M; i++) {
		if (cnt == N - 1) break;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		ll c = edge[i].first;
		if (Find(a) == Find(b)) continue;
		cnt++;
		cost += c;
		Union(a, b);
	}

	if (cnt != N - 1) cout << "impossible";
	else {
		if (cost > tot) cout << "impossible";
		else cout << "possible";
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