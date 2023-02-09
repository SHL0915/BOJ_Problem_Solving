#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, Q;
int table[100001];
vector <vector<int>> tree;

void build(int node, int start, int end);
int query(int node, int start, int end, int left, int right, int k);

void solve() {
	cin >> Q;
	tree.resize(4 * 100000);
	build(1, 1, 100000);
	for (int i = 0; i < Q; i++) {
		cin >> N >> K;
		cout << query(1, 1, 100000, 2, N, K) << '\n';
	}
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	table[1] = 0x3f3f3f3f;
	for (int i = 2; i <= 100000; i++) {
		if (table[i] == 0) {
			for (int j = i; j <= 100000; j += i) table[j] = i;
		}
	}
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node].push_back(table[start]);
		return;
	}
	int mid = (start + end) / 2;
	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);
	vector <int>& l = tree[node * 2], & r = tree[node * 2 + 1];
	tree[node].resize(l.size() + r.size());
	merge(l.begin(), l.end(), r.begin(), r.end(), tree[node].begin());
	return;
}

int query(int node, int start, int end, int left, int right, int k) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return (upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin());
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right, k) + query(node * 2 + 1, mid + 1, end, left, right, k);
}