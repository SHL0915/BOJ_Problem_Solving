#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int tree[100001];
int parent[100001];
set <int> s[100001];
pii query[1500001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) {
		int a; cin >> a;
		tree[i] = a;
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		int a; cin >> a;
		s[i].insert(a);
	}
	for (int i = 0; i < N + Q - 1; i++) {
		int a, b;
		cin >> a >> b;
		query[i] = { a,b };
	}
	vector <int> ans;
	for (int i = N + Q - 2; i >= 0; i--) {
		int a = query[i].first;
		int b = query[i].second;
		if (a == 1) Union(b, tree[b]);		
		else ans.push_back(s[Find(b)].size());		
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
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
	if (s[a].size() > s[b].size()) {
		parent[b] = a;
		for (auto i = s[b].begin(); i != s[b].end(); i++) s[a].insert(*i);
	}
	else {
		parent[a] = b;
		for (auto i = s[a].begin(); i != s[a].end(); i++) s[b].insert(*i);
	}
	return;
}