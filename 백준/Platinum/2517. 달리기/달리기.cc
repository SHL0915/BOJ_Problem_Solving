#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector <long long> arr, compressed, val, tree;

long long query(int node, int start, int end, int left, int right);
void update(int node, int start, int end, int idx);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr.resize(N);
	compressed.resize(N);
	val.resize(N);
	tree.resize(4 * N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		val[i] = arr[i];
	}
	sort(val.begin(), val.end());
	for (int i = 0; i < N; i++) compressed[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin();
	for (int i = 0; i < N; i++) {
		cout << i + 1 - query(1, 0, N - 1, 0, compressed[i] - 1) << '\n';
		update(1, 0, N - 1, compressed[i]);
	}
	return 0;
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] ++;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx);
	update(node * 2 + 1, mid + 1, end, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}