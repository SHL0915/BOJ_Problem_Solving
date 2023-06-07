#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector <pair<int, pii>> edge[100005];
int ans[300005], parent[7005];

void Union(int a, int b);
int Find(int a);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[c].push_back({ i, {a,b} });
	}

	for (int i = 1; i <= 100000; i++) {
		for (auto& [idx, node] : edge[i]) {
			int a = node.first, b = node.second;
			if (Find(a) != Find(b)) ans[idx] = 1;
		}
		for (auto& [idx, node] : edge[i]) {
			int a = node.first, b = node.second;
			Union(a, b);
		}
	}

	for (int i = 0; i < M; i++) {
		if (ans[i]) cout << "TAK\n";
		else cout << "NIE\n";
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
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}