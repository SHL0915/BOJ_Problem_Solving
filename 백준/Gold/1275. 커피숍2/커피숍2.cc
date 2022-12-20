#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector <long long> tree;

void update(int node, int start, int end, int idx, int val);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		int A;
		cin >> A;
		update(1, 1, N, i, A);
	}
	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << query(1, 1, N, min(x, y), max(x, y)) << '\n';
		update(1, 1, N, a, b);
	}
	return 0;
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}