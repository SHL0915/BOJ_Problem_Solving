#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1000000007LL;

int N, M, K;
vector <long long> arr, tree;

void CreateSegTree(int node, int start, int end);
void update(int node, int start, int end, int idx, long long val);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	tree.resize(4 * N);
	CreateSegTree(1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, N - 1, b - 1, c);
		else cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
	}
	return 0;
}

void CreateSegTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	CreateSegTree(node * 2, start, mid);
	CreateSegTree(node * 2 + 1, mid + 1, end);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
	return;
}

void update(int node, int start, int end, int idx, long long val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		arr[idx] = val;
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
}

long long query(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % mod;
}