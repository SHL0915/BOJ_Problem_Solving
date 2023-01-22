#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
int arr[1000001];
vector <int> val, tree;

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	tree.resize(4 * N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		val.push_back(arr[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());	
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(val.begin(), val.end(), arr[i]) - val.begin() + 1;
		int q = query(1, 1, N, 1, idx - 1);
		ans = max(ans, q + 1);
		update(1, 1, N, idx, q + 1);
	}
	cout << ans;
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
		tree[node] = max(tree[node], val);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}