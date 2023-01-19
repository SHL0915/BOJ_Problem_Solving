#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, T;
pii arr[100001];
vector <int> x, y, tree;

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N >> M >> T;
	tree.resize(4 * T);
	for (int i = 0; i < T; i++) {
		cin >> arr[i].second >> arr[i].first;
		x.push_back(arr[i].first);
		y.push_back(arr[i].second);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	for (int i = 0; i < T; i++) {
		arr[i].first = lower_bound(x.begin(), x.end(), arr[i].first) - x.begin();
		arr[i].second = lower_bound(y.begin(), y.end(), arr[i].second) - y.begin();
	}
	sort(arr, arr + T);
	for (int i = T - 1; i >= 0; i--) {
		int x_idx = arr[i].first, y_idx = arr[i].second;		
		if (x[x_idx] > M || y[y_idx] > N) continue;
		update(1, 0, T - 1, y_idx, query(1, 0, T - 1, y_idx, T - 1) + 1);
	}
	cout << query(1, 0, T - 1, 0, T - 1) << '\n';
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
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}