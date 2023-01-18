#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100001];
int ans[100001];
vector <int> tree;

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);
int BinarySearch(int left, int right, int val);

void solve() {
	cin >> N;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(1, 1, N, i, 1);
	}
	for (int i = N; i >= 1; i--) {
		int idx = BinarySearch(1, N, arr[i] + 1);
		ans[idx] = i;
		update(1, 1, N, idx, 0);
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << " ";
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void update(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int BinarySearch(int left, int right, int val) {
	if (left < right) {
		int mid = (left + right) / 2;
		int q = query(1, 1, N, mid, N);
		if (q > val) return BinarySearch(mid + 1, right, val);
		else if (q == val) {
			if (query(1, 1, N, mid, mid) == 1) return mid;
			else return BinarySearch(mid + 1, right, val);
		}
		else return BinarySearch(left, mid - 1, val);
	}
	else return left;
}