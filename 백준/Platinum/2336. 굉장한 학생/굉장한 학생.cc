#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int turn[500001];
pii arr[500001];
vector <int> tree;

void update(int node, int start, int end, int idx, int val);
int query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	int cnt = 0;
	tree.resize(4 * N, INF);
	for (int i = 1; i <= N; i++) cin >> turn[i];
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		arr[a].first = i;
	}
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		arr[a].second = i;
	}
	for (int i = 1; i <= N; i++) {
		int now = turn[i];
		if (query(1, 1, N, 1, arr[now].second) > arr[now].first) cnt++;
		update(1, 1, N, arr[now].second, arr[now].first);
	}
	cout << cnt;
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
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	return;
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}