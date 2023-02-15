#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int M;
map <string, int> convert;
int parent[200001];
int sz[200001];

int Find(int a);
void Union(int a, int b);

void solve() {
	convert.clear();
	cin >> M;
	int id = 1;
	for (int i = 1; i <= 200001; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		string a, b;
		cin >> a >> b;
		if (convert[a] == 0) convert[a] = id++;
		if (convert[b] == 0) convert[b] = id++;
		Union(convert[a], convert[b]);
		cout << sz[Find(convert[a])] << '\n';
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
	cin >> t;
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
	if (a > b) {
		parent[a] = b;
		sz[b] += sz[a];
	}
	else {
		parent[b] = a;
		sz[a] += sz[b];
	}
	return;
}