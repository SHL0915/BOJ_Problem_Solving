#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
	int front = 0, back = 0, len = 0, l = 0, r = 0, max = 0;
};

int N, Q;
int arr[200005], idx[200005];
node seg[800005];

node merge(node a, node b) {
	node ret;
	ret.front = a.front;
	ret.back = b.back;
	ret.len = a.len + b.len;
	if (a.l == a.len && b.front > a.back) ret.l = a.len + b.l;
	else ret.l = a.l;
	if (b.r == b.len && b.front > a.back) ret.r = b.len + a.r;
	else ret.r = b.r;
	ret.max = max(a.max, b.max);
	if (b.front > a.back) ret.max = max(ret.max, a.r + b.l);
	return ret;
}

void update(int n, int s, int e, int pos, int val) {
	if (pos > e || pos < s) return;
	if (s == e) {
		seg[n] = { val, val, 1, 1, 1, 1 };
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, pos, val);
	update(n * 2 + 1, mid + 1, e, pos, val);
	seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
	return;
}

node query(int n, int s, int e, int l, int r) {
	if (l > e || r < s) return { 0,0,0,0,0,0 };
	if (l <= s && e <= r) return seg[n];
	int mid = (s + e) / 2;
	return merge(query(n * 2, s, mid, l, r), query(n * 2 + 1, mid + 1, e, l, r));
}

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		idx[arr[i]] = i;
		update(1, 1, N, arr[i], i);	
	}

	cout << N - query(1, 1, N, 1, N).max << '\n';
	while (Q--) {
		int a, b;
		cin >> a >> b;
		swap(arr[a], arr[b]);
		update(1, 1, N, arr[a], a);
		update(1, 1, N, arr[b], b);
		cout << N - query(1, 1, N, 1, N).max << '\n';
	}

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}