#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, SZ;
ll org[100001];
ll arr[100001];
vector <ll> val;
pair <int, pii> query[100001];
ll seg[1200505];

void update(int pos, ll val);
ll seg_query(int l, int r);
ll BinarySearch(ll l, ll r, ll val);

void solve() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> org[i];
		arr[i] = org[i];
		val.push_back(org[i]);
	}

	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		if (a == 1) {
			ll b, c;
			cin >> b >> c;
			arr[b] += c;
			val.push_back(arr[b]);
			query[i] = { a, {b,c} };
		}
		else if (a == 2) {
			ll b, c;
			cin >> b >> c;
			arr[b] -= c;
			val.push_back(arr[b]);
			query[i] = { a, {b,c} };
		}
		else if (a == 3) {
			ll b, c;
			cin >> b >> c;
			val.push_back(b); val.push_back(c);
			query[i] = { a, {b,c} };
		}
		else {
			ll b;
			cin >> b;
			query[i] = { a, {b,0} };
		}
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	SZ = val.size();

	for (int i = 1; i <= N; i++) {
		int idx = lower_bound(val.begin(), val.end(), org[i]) - val.begin() + 1;
		update(idx, 1);
		arr[i] = org[i];
	}

	for (int i = 0; i < M; i++) {
		int a = query[i].first;
		if (a == 1) {
			ll b = query[i].second.first;
			ll c = query[i].second.second;
			int idx = lower_bound(val.begin(), val.end(), arr[b]) - val.begin() + 1;
			update(idx, -1);
			arr[b] += c;
			idx = lower_bound(val.begin(), val.end(), arr[b]) - val.begin() + 1;
			update(idx, 1);
		}
		else if (a == 2) {
			ll b = query[i].second.first;
			ll c = query[i].second.second;
			int idx = lower_bound(val.begin(), val.end(), arr[b]) - val.begin() + 1;
			update(idx, -1);
			arr[b] -= c;
			idx = lower_bound(val.begin(), val.end(), arr[b]) - val.begin() + 1;
			update(idx, 1);
		}
		else if (a == 3) {
			ll b = query[i].second.first;
			ll c = query[i].second.second;
			int l = lower_bound(val.begin(), val.end(), b) - val.begin() + 1;
			int r = lower_bound(val.begin(), val.end(), c) - val.begin() + 1;
			cout << seg_query(l, r + 1) << '\n';
		}
		else {
			ll b = query[i].second.first;
			ll ans = BinarySearch(1, SZ + 1, b);
			if (seg_query(ans, SZ + 1) < b) ans--;

			cout << val[ans - 1] << '\n';
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

void update(int pos, ll val) {
	for (seg[pos += SZ] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
	return;
}

ll seg_query(int l, int r) {
	ll ret = 0;
	for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += seg[l++];
		if (r & 1) ret += seg[--r];
	}
	return ret;
}

ll BinarySearch(ll l, ll r, ll val) {
	ll mid = (l + r) / 2;
	if (l < r) {
		if (seg_query(mid, SZ + 1) < val) return BinarySearch(l, mid - 1, val);
		else return BinarySearch(mid + 1, r, val);
	}
	else return mid;
}