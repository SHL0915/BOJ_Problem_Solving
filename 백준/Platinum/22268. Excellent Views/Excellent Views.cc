#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];
ll seg[200005];

void update(int pos, ll val) {
	for (seg[pos += N] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
	return;
}

ll query(int l, int r) {
	r++;
	ll ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += seg[l++];
		if (r & 1) ret += seg[--r];
	}
	return ret;
}

void solve() {
	cin >> N;
	priority_queue <pii> pq;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		pq.push({ arr[i], i });
	}

	set <int> pos;

	auto i = pos.lower_bound(0);
	
	for (int i = 0; i < N; i++) {
		pii now = pq.top();
		pq.pop();

		int idx = now.second;
		auto l = pos.lower_bound(idx);
		auto r = pos.upper_bound(idx);

		int lval, rval;

		if (l != pos.begin() && r != pos.end()) {
			l--;
			lval = idx - (idx - *l - 1) / 2;
			rval = idx + (*r - idx - 1) / 2;
		}
		else if (l != pos.begin()) {
			l--;
			lval = idx - (idx - *l - 1) / 2;
			rval = N - 1;
		}
		else if (r != pos.end()) {
			lval = 0;
			rval = idx + (*r - idx - 1) / 2;
		}
		else {
			lval = 0;
			rval = N - 1;
		}
		
		update(lval + 1, 1);
		update(rval + 2, -1);
		pos.insert(idx);
	}
	
	for (int i = 1; i <= N; i++) cout << query(1, i) - 1 << " ";

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
