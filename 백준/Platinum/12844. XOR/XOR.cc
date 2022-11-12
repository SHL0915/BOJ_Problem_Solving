#include <iostream>
#include <vector>
using namespace std;

int N, Q;
long long arr[500001];
vector <long long> tree, lazy;

void createSegTree(int node, int start, int end);
void update_lazy(int node, int start, int end);
void update(int node, int start, int end, int left, int right, long long val);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	tree.resize(4 * N);
	lazy.resize(4 * N);
	createSegTree(1, 0, N - 1);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int A, B, C, D;
		cin >> A >> B >> C;
		if (A == 1) {
			cin >> D;
			update(1, 0, N - 1, B, C, D);
		}
		else cout << query(1, 0, N - 1, B, C) << '\n';
	}
	return 0;
}

void createSegTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	createSegTree(node * 2, start, mid);
	createSegTree(node * 2 + 1, mid + 1, end);
	tree[node] = (tree[node * 2] ^ tree[node * 2 + 1]);
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		if((end - start + 1) % 2 == 1) tree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];			
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right, long long val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] ^= val;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	tree[node] = (tree[node * 2] ^ tree[node * 2 + 1]);
	return;
}

long long query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right));
}