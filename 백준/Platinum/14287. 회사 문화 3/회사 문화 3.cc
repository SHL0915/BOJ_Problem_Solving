#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
vector <int> graph[100001];
vector <ll> tree;
pii ETT[100001];

void update(int node, int start, int end, int idx, ll val);
ll query(int node, int start, int end, int left, int right);

void DFS(int node);

void solve() {
	cin >> N >> M;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a == -1) continue;
		else graph[a].push_back(i);
	}
	DFS(1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			update(1, 1, N, ETT[b].first, c);
		}
		else cout << query(1, 1, N, ETT[b].first, ETT[b].second) << '\n';
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

void DFS(int node) {
	cnt++;
	ETT[node].first = cnt;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
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