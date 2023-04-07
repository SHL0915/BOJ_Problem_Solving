#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int graph[51][51];
int parent[51];
vector <pair<int, pii>> edge;

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) parent[i] = i;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '0') continue;
			else if (s[j] >= 'a' && s[j] <= 'z') graph[i][j] = s[j] - 'a' + 1;
			else if (s[j] >= 'A' && s[j] <= 'Z') graph[i][j] = s[j] - 'A' + 27;
		}
	}

	int tot = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j]) edge.push_back({ graph[i][j], {i,j} });
			tot += graph[i][j];
		}
	}

	sort(edge.begin(), edge.end());
	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < edge.size(); i++) {
		if (cnt == N - 1) break;
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		cnt++;
		ans += cost;
	}

	if (cnt != N - 1) cout << -1;
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