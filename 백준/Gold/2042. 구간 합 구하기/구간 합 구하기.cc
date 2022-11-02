#include <iostream>
#include <vector>
using namespace std;

long long N, M, K;
vector <long long> arr;
vector <long long> tree;

void CreateSegTree(int node, int start, int end);
long long Calculate(int node, int start, int end, int left, int right);
void Update(int node, int start, int end, int idx, long long val);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;
		arr.push_back(input);
	}
	tree.resize(4 * N);
	CreateSegTree(1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) Update(1, 0, N - 1, b - 1, c);
		else cout << Calculate(1, 0, N - 1, b - 1, c - 1) << '\n';
		
	}
}

void CreateSegTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	CreateSegTree(node * 2, start, (start + end) / 2);
	CreateSegTree(node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

long long Calculate(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	else if (left <= start && end <= right) return tree[node];
	else {
		long long lsum = Calculate(node * 2, start, (start + end) / 2, left, right);
		long long rsum = Calculate(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
		return lsum + rsum;
	}
}

void Update(int node, int start, int end, int idx, long long val) {
	if (idx < start || idx > end) return;
	if (start == end) {
		arr[idx] = val;
		tree[node] = val;
		return;
	}
	Update(node * 2, start, (start + end) / 2, idx, val);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}