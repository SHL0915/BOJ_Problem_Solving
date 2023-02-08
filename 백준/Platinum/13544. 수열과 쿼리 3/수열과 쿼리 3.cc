#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, ans;
int arr[100001];
vector <vector<int>> tree;

void build(int node, int start, int end);
int query(int node, int start, int end, int left, int right, int k);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	tree.resize(4 * N);
	build(1, 1, N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a ^= ans;
		b ^= ans;
		c ^= ans;
		ans = query(1, 1, N, a, b, c);
		cout << ans << '\n';
	}
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node].push_back(arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);
	vector <int>& l = tree[node * 2], & r = tree[node * 2 + 1];
	tree[node].resize(l.size() + r.size());
	merge(l.begin(), l.end(), r.begin(), r.end(), tree[node].begin());
	return;
}

int query(int node, int start, int end, int left, int right, int k) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return (tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k));
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right, k) + query(node * 2 + 1, mid + 1, end, left, right, k);
}