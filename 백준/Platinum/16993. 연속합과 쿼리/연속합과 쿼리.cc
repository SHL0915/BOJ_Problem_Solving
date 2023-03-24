#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct seg_node {
	int front, back, max_val, sum;

	seg_node() {
		front = -INF;
		back = -INF;
		max_val = -INF;
		sum = 0;
	}
};

int N, M;
int arr[100001];
vector <seg_node> seg;

void init(int node, int start, int end);
seg_node query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	seg.resize(4 * N);
	for (int i = 1; i <= N; i++) cin >> arr[i];
	init(1, 1, N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, N, l, r).max_val << '\n';
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

void init(int node, int start, int end) {
	if (start == end) {
		seg[node].front = arr[start];
		seg[node].back = arr[start];
		seg[node].max_val = arr[start];
		seg[node].sum = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	seg[node].front = max(seg[node * 2].front, seg[node * 2].sum + seg[node * 2 + 1].front);
	seg[node].back = max(seg[node * 2 + 1].back, seg[node * 2 + 1].sum + seg[node * 2].back);
	seg[node].max_val = max({ seg[node * 2].max_val, seg[node * 2 + 1].max_val, seg[node * 2].back + seg[node * 2 + 1].front });
	seg[node].sum = seg[node * 2].sum + seg[node * 2 + 1].sum;
	return;
}

seg_node query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		seg_node empty;
		return empty;
	};
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	seg_node l = query(node * 2, start, mid, left, right), r = query(node * 2 + 1, mid + 1, end, left, right);
	seg_node ret;
	ret.front = max(l.front, l.sum + r.front);
	ret.back = max(r.back, r.sum + l.back);
	ret.max_val = max({ l.max_val, r.max_val, l.back + r.front });
	ret.sum = l.sum + r.sum;
	return ret;
}