#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, T;
vector <pii> tree[50005];

pair<int, pii> DFS(int node, int par);

void solve() {
	cin >> N >> T;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	pair<int, pii> root = DFS(1, 1);
	pair<int, pii> ans = DFS(root.first, root.first);

	cout << (ans.second.second - 1) / T + 1;
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

pair<int, pii> DFS(int node, int par) {
	vector <pair<int, pii>> arr;
	arr.push_back({ node, {0, 0} });

	for (auto& [next, cost] : tree[node]) {
		if (next == par) continue;
		pair<int, pii> res = DFS(next, node);
		res.second.first++;
		res.second.second += cost;
		arr.push_back(res);
	}

	sort(arr.begin(), arr.end(), [&](pair<int, pii> a, pair<int, pii> b) {
		if (a.second.first == b.second.first) return a.second.second < b.second.second;
		return a.second.first > b.second.first;
		});

	return arr[0];
}