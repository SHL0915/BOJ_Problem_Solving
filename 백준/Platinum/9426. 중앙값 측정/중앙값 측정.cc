#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 65535;

int N, K;
int arr[250001];
vector <int> tree;

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);
ll BinarySearch(int left, int right, int val);

void solve() {
	cin >> N >> K;
	tree.resize(4 * SZ);
	ll ans = 0;
	for (int i = 0; i < K - 1; i++) {
		cin >> arr[i];
		update(1, 0, SZ, arr[i], 1);
	}
	for (int i = K - 1; i < N; i++) {
		cin >> arr[i];
		update(1, 0, SZ, arr[i], 1);
		ans += BinarySearch(0, SZ, (K + 1) / 2);
		update(1, 0, SZ, arr[i - (K - 1)], -1);
	}
	cout << ans << '\n';
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

ll BinarySearch(int left, int right, int val) {
	if (left < right) {
		int mid = (left + right) / 2;
		int q = query(1, 0, SZ, 0, mid);
		if (q >= val) return BinarySearch(left, mid, val);
		else return BinarySearch(mid + 1, right, val);
	}
	else return left;
}