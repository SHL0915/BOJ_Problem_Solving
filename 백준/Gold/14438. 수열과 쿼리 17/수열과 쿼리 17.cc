#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000000LL;

int N, M;
vector <long long> arr, tree;

void CreateSegTree(int node, int start, int end);
void update(int node, int start, int end, int idx, long long val);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr.resize(N);
	tree.resize(4 * N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	CreateSegTree(1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		long long type, A, B;
		cin >> type >> A >> B;
		if (type == 1) update(1, 0, N - 1, A - 1, B);
		else cout << query(1, 0, N - 1, A - 1, B - 1) << '\n';
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
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	return;
}

void update(int node, int start, int end, int idx, long long val) {
	if (idx < start || idx > end) return;
	if (start == end) {
		arr[idx] = val;
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	return;
}

long long query(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}