#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100001;

int N, M;
vector <int> tree;
int C[SZ], W[SZ], B[SZ];

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);
int BinarySearch(int left, int right, int val);

void solve() {
	cin >> N >> M;
	tree.resize(4 * SZ);
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
		update(1, 1, SZ, C[i], 1);
	}
	for (int i = 1; i <= M; i++) cin >> W[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
	for (int i = 1; i <= M; i++) {
		int idx = BinarySearch(1, SZ, B[i]);
		if (query(1, 1, SZ, idx, SZ) < B[i]) idx--;
		if (idx < W[i]) {
			cout << 0 << '\n';
			return;
		}
		update(1, 1, SZ, idx - W[i], 1);
		update(1, 1, SZ, idx, -1);
	}
	cout << 1 << '\n';
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
		tree[node] += val;
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
	return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right));
}

int BinarySearch(int left, int right, int val) {
	if (left < right) {
		int mid = (left + right) / 2;
		int q = query(1, 1, SZ, mid, SZ);
		if (q < val) return BinarySearch(left, mid - 1, val);
		else return BinarySearch(mid + 1, right, val);
	}
	else return left;
}