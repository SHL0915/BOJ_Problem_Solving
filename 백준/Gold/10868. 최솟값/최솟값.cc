#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1000000000000L;

int N, M;
vector <long long> arr, tree;

void CreateSegTree(int node, int start, int end);
long long query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	tree.resize(4 * N);
	CreateSegTree(1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(1, 0, N - 1, a - 1, b - 1) << '\n';
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

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}