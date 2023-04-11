#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[500001];
vector <ll> seg;

void update(int node, int start, int end, int idx, ll val);
ll query(int node, int start, int end, int left, int right);

void solve() {
	seg.clear();
	seg.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr + 1, arr + N + 1);

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ll now = arr[i].first, idx = arr[i].second;
		ans += query(1, 1, N, idx + 1, N);
		update(1, 1, N, idx, 1);
	}

	cout << ans << '\n';
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
	while (1) {
		cin >> N;
		if (N == 0) break;
		solve();
	}
	return 0;
}

void update(int node, int start, int end, int idx, ll val) {
	if (idx > end || idx < start) return;
	if (start == end) {
		seg[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	return;
}

ll query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}