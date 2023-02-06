#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int tree[200001];
int parent[200001];
pair<int, pii> query[400001];

int Find(int a);
void Union(int a, int b);

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 2; i <= N; i++) {
		int a; cin >> a;
		tree[i] = a;
	}
	for (int i = 0; i < N - 1 + Q; i++) {
		int a, b, c = 0;
		cin >> a;
		if (a) cin >> b >> c;
		else cin >> b;
		query[i] = { a, {b,c} };
	}
	vector <int> ans;
	for (int i = N - 1 + Q - 1; i >= 0; i--) {
		int a = query[i].first;
		int b = query[i].second.first;
		int c = query[i].second.second;
		if (a) {
			if (Find(b) == Find(c)) ans.push_back(1);
			else ans.push_back(0);
		}
		else Union(b, tree[b]);
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i]) cout << "YES\n";
		else cout << "NO\n";
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

int Find(int a) {
	if (parent[a] == a) return parent[a];
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