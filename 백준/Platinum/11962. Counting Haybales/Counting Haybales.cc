#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct segnode {
	ll min, sum;
	segnode() {
		min = INF; sum = 0;
	}
};

ll N, Q;
ll arr[200001];
vector <segnode> seg;
vector <ll> lazy;

void init(int node, ll start, ll end);
void update(int node, ll start, ll end, ll left, ll right, ll val);
void update_lazy(int node, ll start, ll end);
segnode query(int node, ll start, ll end, ll left, ll right);

void solve() {
	cin >> N >> Q;

	seg.resize(4 * N);
	lazy.resize(4 * N);

	for (int i = 1; i <= N; i++) cin >> arr[i];
	init(1, 1, N);

	for (int i = 0; i < Q; i++) {
		char ch; cin >> ch;
		if (ch == 'M') {
			ll a, b; cin >> a >> b;
			cout << query(1, 1, N, a, b).min << '\n';
		}
		else if (ch == 'P') {
			ll a, b, c; cin >> a >> b >> c;
			update(1, 1, N, a, b, c);
		}
		else {
			ll a, b; cin >> a >> b;
			cout << query(1, 1, N, a, b).sum << '\n';
		}
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

void init(int node, ll start, ll end) {
	if (start == end) {
		seg[node].min = arr[start];
		seg[node].sum = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg[node].min = min(seg[node * 2].min, seg[node * 2 + 1].min);
	seg[node].sum = seg[node * 2].sum + seg[node * 2 + 1].sum;
	return;
}

void update(int node, ll start, ll end, ll left, ll right, ll val) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node] += val;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node].min = min(seg[node * 2].min, seg[node * 2 + 1].min);
	seg[node].sum = seg[node * 2].sum + seg[node * 2 + 1].sum;
	return;
}

void update_lazy(int node, ll start, ll end) {
	if (lazy[node]) {
		seg[node].sum += lazy[node] * (end - start + 1);
		seg[node].min += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

segnode query(int node, ll start, ll end, ll left, ll right) {
	update_lazy(node, start, end);
	if (left > end || right < start) {
		segnode empty;
		return empty;
	}
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	segnode ret;
	segnode l = query(node * 2, start, mid, left, right);
	segnode r = query(node * 2 + 1, mid + 1, end, left, right);
	ret.min = min(l.min, r.min);
	ret.sum = l.sum + r.sum;
	return ret;
}