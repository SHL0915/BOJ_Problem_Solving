#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K, Q, A, B;
vector <int> min_tree, max_tree;

void update_min(int node, int start, int end, int idx, int val);
void update_max(int node, int start, int end, int idx, int val);
int query_min(int node, int start, int end, int left, int right);
int query_max(int node, int start, int end, int left, int right);

void solve() {
	cin >> N >> K;
	min_tree.resize(4 * N, INF);
	max_tree.resize(4 * N, -INF);
	for (int i = 0; i < N; i++) {
		update_min(1, 0, N - 1, i, i);
		update_max(1, 0, N - 1, i, i);
	}
	for (int i = 0; i < K; i++) {
		cin >> Q >> A >> B;
		if (Q) {
			if (query_min(1, 0, N - 1, A, B) == A && query_max(1, 0, N - 1, A, B) == B) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			int a = query_max(1, 0, N - 1, A, A), b = query_max(1, 0, N - 1, B, B);
			update_max(1, 0, N - 1, A, b);
			update_max(1, 0, N - 1, B, a);
			update_min(1, 0, N - 1, A, b);
			update_min(1, 0, N - 1, B, a);
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void update_min(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		min_tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update_min(node * 2, start, mid, idx, val);
	update_min(node * 2 + 1, mid + 1, end, idx, val);
	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	return;
}

void update_max(int node, int start, int end, int idx, int val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		max_tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update_max(node * 2, start, mid, idx, val);
	update_max(node * 2 + 1, mid + 1, end, idx, val);
	max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
	return;
}

int query_min(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return min_tree[node];
	int mid = (start + end) / 2;
	return min(query_min(node * 2, start, mid, left, right), query_min(node * 2 + 1, mid + 1, end, left, right));
}

int query_max(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -INF;
	if (left <= start && end <= right) return max_tree[node];
	int mid = (start + end) / 2;
	return max(query_max(node * 2, start, mid, left, right), query_max(node * 2 + 1, mid + 1, end, left, right));
}