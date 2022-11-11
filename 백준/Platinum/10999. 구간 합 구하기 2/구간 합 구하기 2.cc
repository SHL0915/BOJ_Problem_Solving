#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
long long arr[1000001];
vector <long long> tree, lazy;

void createSegTree(int node, int start, int end);
long long query(int node, int start, int end, int left, int right);
void updateLazy(int node, int start, int end);
void update(int node, int start, int end, int left, int right, long long diff);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	tree.resize(4 * N);
	lazy.resize(4 * N);
	createSegTree(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		long long A, B, C, D;
		cin >> A >> B >> C;
		if (A == 1) {
			cin >> D;
			update(1, 1, N, B, C, D);
		}
		else cout << query(1, 1, N, B, C) << '\n';		
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

long long query(int node, int start, int end, int left, int right) {
	updateLazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];	
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void updateLazy(int node, int start, int end) {
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


void update(int node, int start, int end, int left, int right, long long diff) {
	updateLazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] += diff;
		updateLazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
	return;
}