#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 200001;

int N, C, Q, cnt;
ll level[SZ];
vector <int> graph[SZ];
pii ETT[SZ];
vector <ll> tree;

void DFS(int node, int par, int lv);
void update(int node, int start, int end, int idx, ll val);
ll query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N >> C;
	tree.resize(4 * N);
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	DFS(C, -1, 1);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) update(1, 1, N, ETT[b].first, 1);
		else cout << level[b] * query(1, 1, N, ETT[b].first, ETT[b].second) << '\n';
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void DFS(int node, int par, int lv) {
	cnt++;
	ETT[node].first = cnt;
	level[node] = lv;
	for (int i = 0; i < graph[node].size(); i++) {
		if (graph[node][i] == par) continue;
		DFS(graph[node][i], node, lv + 1);
	}
	ETT[node].second = cnt;
	return;
}

void update(int node, int start, int end, int idx, ll val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] += val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

ll query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right));
}