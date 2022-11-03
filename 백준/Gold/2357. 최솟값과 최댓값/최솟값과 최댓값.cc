#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long INF = 1000000000000LL;

int N, M;
vector <long long> arr;
vector <long long> min_tree, max_tree;

void CreateMinSegTree(int node, int start, int end);
void CreateMaxSegTree(int node, int start, int end);
long long find_min(int node, int start, int end, int left, int right);
long long find_max(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	min_tree.resize(4 * N);
	max_tree.resize(4 * N);
	CreateMinSegTree(1, 0, N - 1);
	CreateMaxSegTree(1, 0, N - 1);
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << find_min(1, 0, N - 1, a - 1, b - 1) << " " << find_max(1, 0, N - 1, a - 1, b - 1) << '\n';
	}
	return 0;
}

void CreateMinSegTree(int node, int start, int end) {
	if (start == end) {
		min_tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	CreateMinSegTree(node * 2, start, mid);
	CreateMinSegTree(node * 2 + 1, mid + 1, end);
	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	return;
}

void CreateMaxSegTree(int node, int start, int end) {
	if (start == end) {
		max_tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	CreateMaxSegTree(node * 2, start, mid);
	CreateMaxSegTree(node * 2 + 1, mid + 1, end);
	max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}

long long find_min(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return INF;
	if (left <= start && end <= right) return min_tree[node];
	int mid = (start + end) / 2;
	return min(find_min(node * 2, start, mid, left, right), find_min(node * 2 + 1, mid + 1, end, left, right));
}

long long find_max(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return -1;
	if (left <= start && end <= right) return max_tree[node];
	int mid = (start + end) / 2;
	return max(find_max(node * 2, start, mid, left, right), find_max(node * 2 + 1, mid + 1, end, left, right));
}