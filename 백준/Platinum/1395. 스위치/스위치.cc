#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <long long> tree, lazy;

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		if (lazy[node] % 2 == 1) tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

void update(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] ++;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right);
	update(node * 2 + 1, mid + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

long long query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	tree.resize(4 * N);
	lazy.resize(4 * N);
	for (int i = 0; i < M; i++) {
		int O, S, T;
		cin >> O >> S >> T;
		if (O == 0) update(1, 1, N, S, T);
		else cout << query(1, 1, N, S, T) << '\n';
	}
	return 0;
}