#include <iostream>
#include <vector>
using namespace std;

int N, Q;
long long arr[100001];
vector <long long> tree;
vector <pair<long long, long long>> lazy;

void createSegTree(int node, int start, int end);
void update_lazy(int node, int start, int end);
void update(int node, int start, int end, int left, int right);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	tree.resize(4 * N);
	lazy.resize(4 * N);
	createSegTree(1, 1, N);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int A, B, C;
		cin >> A >> B;
		if (A == 1) {
			cin >> C;
			update(1, 1, N, B, C);
		}
		else cout << query(1, 1, N, B, B) << '\n';
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
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node].first != 0) {
		tree[node] += (lazy[node].first * (end - start + 1) + lazy[node].second * (end - start) * (end - start + 1) / 2);
		if (start != end) {
			lazy[node * 2].first += lazy[node].first;
			lazy[node * 2].second += lazy[node].second;
			lazy[node * 2 + 1].first += lazy[node].first + (end - start + 2) / 2 * lazy[node].second;
			lazy[node * 2 + 1].second += lazy[node].second;
		}
		lazy[node] = { 0,0 };
	}
}

void update(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node].first += (start - left + 1);
		lazy[node].second++;
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
