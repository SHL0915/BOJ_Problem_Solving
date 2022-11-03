#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <long long> arr, tree;

void CreateSegTree(int node, int start, int end);
void update(int node, int start, int end, int idx, long long val);
int query(int node, int start, int end, int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	tree.resize(4 * N);
	CreateSegTree(1, 0, N - 1);
	cin >> M;
	for(int i = 0; i < M; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, N - 1, b - 1, c);
		else cout << query(1, 0, N - 1, b - 1, c - 1) + 1 << '\n';
	}
	return 0;
}

void CreateSegTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
		return;
	}
	int mid = (start + end) / 2;
	CreateSegTree(node * 2, start, mid);
	CreateSegTree(node * 2 + 1, mid + 1, end);
	if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
	else tree[node] = tree[node * 2 + 1];
	return;
}

void update(int node, int start, int end, int idx, long long val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		arr[start] = val;
		tree[node] = start;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
	else tree[node] = tree[node * 2 + 1];
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	int lans = query(node * 2, start, mid, left, right);
	int rans = query(node * 2 + 1, mid + 1, end, left, right);
	if (lans == -1) return rans;
	else if (rans == -1) return lans;
	else {
		if (arr[lans] <= arr[rans]) return lans;
		else return rans;
	}
}