#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
vector <int> graph[500001];
ll arr[500001];
pii id[500001];
vector <ll> tree, lazy;

void ETT(int node);
void update(int node, int start, int end, int left, int right, ll val);
void update_lazy(int node, int start, int end);
ll query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N >> M;
	tree.resize(4 * N);
	lazy.resize(4 * N);
	cin >> arr[1];
	for (int i = 2; i <= N; i++) {
		cin >> arr[i];
		int a; cin >> a;
		graph[a].push_back(i);
	}
	ETT(1);
	for (int i = 1; i <= N; i++) update(1, 1, N, id[i].first, id[i].first, arr[i]);	
	for (int i = 0; i < M; i++) {
		char oper; cin >> oper;
		if (oper == 'p') {
			int a, b;
			cin >> a >> b;
			if (id[a].first == id[a].second) continue;
			update(1, 1, N, id[a].first + 1, id[a].second, b);
		}
		else {
			int a; cin >> a;
			cout << query(1, 1, N, id[a].first, id[a].first) << '\n';
		}
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

void ETT(int node) {
	cnt++;
	id[node].first = cnt;
	for (int i = 0; i < graph[node].size(); i++) ETT(graph[node][i]);
	id[node].second = cnt;
	return;
}

void update(int node, int start, int end, int left, int right, ll val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] += val;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node] * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

ll query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right));
}