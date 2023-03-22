#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 1000000007;

int N, M;
vector<ll> seg;
vector<pii> lazy;

void update(int node, int start, int end, int left, int right, ll sum, ll product);
void update_lazy(int node, int start, int end);
ll query(int node, int start, int end, int left, int right);

void solve() {
	cin >> N;
	seg.resize(4 * N);
	lazy.resize(4 * N, { 0,1 });

	for (int i = 1; i <= N; i++) {
		ll a; cin >> a;
		update(1, 1, N, i, i, a, 1);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		if (a == 1) {
			ll x, y, v;
			cin >> x >> y >> v;
			update(1, 1, N, x, y, v, 1);
		}
		else if (a == 2) {
			ll x, y, v;
			cin >> x >> y >> v;
			update(1, 1, N, x, y, 0, v);
		}
		else if (a == 3) {
			ll x, y, v;
			cin >> x >> y >> v;
			update(1, 1, N, x, y, 0, 0);
			update(1, 1, N, x, y, v, 1);
		}
		else {
			ll x, y;
			cin >> x >> y;
			cout << query(1, 1, N, x, y) << '\n';
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

void update(int node, int start, int end, int left, int right, ll sum, ll product) {
	update_lazy(node, start, end);
	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		lazy[node].first *= product; lazy[node].first = mod;
		lazy[node].first += sum; lazy[node].first %= mod;
		lazy[node].second *= product; lazy[node].second %= mod;
		update_lazy(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, sum, product);
	update(node * 2 + 1, mid + 1, end, left, right, sum, product);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	seg[node] %= mod;
	return;
}

void update_lazy(int node, int start, int end) {
	ll& f = lazy[node].first;
	ll& s = lazy[node].second;
	if (f == 0 && s == 1) return;
	seg[node] = (seg[node] * s + (end - start + 1) * f) % mod;
	if (start != end) {
		lazy[node * 2] = { (lazy[node * 2].first * s + f) % mod, (lazy[node * 2].second * s) % mod };
		lazy[node * 2 + 1] = { (lazy[node * 2 + 1].first * s + f) % mod, (lazy[node * 2 + 1].second * s) % mod };
	}
	f = 0; s = 1;
	return;
}

ll query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg[node] % mod;
	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)) % mod;
}