#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[100001];
vector <ll> val, seg, lazy;

void update(int node, int start, int end, int left, int right, ll val);
void update_lazy(int node, int start, int end);
ll query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;

	seg.resize(8 * N);
	lazy.resize(8 * N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		val.push_back(arr[i].second);
		val.push_back(arr[i].first + arr[i].second - 1);
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for (int i = 0; i < N; i++) {
		ll l = lower_bound(val.begin(), val.end(), arr[i].second) - val.begin() + 1;
		ll r = lower_bound(val.begin(), val.end(), arr[i].first + arr[i].second - 1) - val.begin() + 1;

		ll h = query(1, 1, 2 * N, l, r);

		update(1, 1, 2 * N, l, r, h + 1);
	}

	cout << query(1, 1, 2 * N, 1, 2 * N);
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

void update(int node, int start, int end, int left, int right, ll val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] = max(lazy[node], val);
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
	return;
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		seg[node] = max(seg[node], lazy[node]);
		if (start != end) {
			lazy[node * 2] = max(lazy[node], lazy[node * 2]);
			lazy[node * 2 + 1] = max(lazy[node], lazy[node * 2 + 1]);
		}
		lazy[node] = 0;
	}
	return;
}

ll query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}
