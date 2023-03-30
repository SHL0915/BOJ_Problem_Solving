#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll SZ = 100005;

ll N, M, K, B, cnt;
ll tree[105005];
int arr[100001];
pair<pii, int> query[100001];
ll ans[100001];

bool cmp(pair<pii, int> a, pair<pii, int> b);
void push(int a);
void pop(int a);
void update(int pos, ll val);
ll fenwick_query(int idx);

void solve() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	cin >> M;
	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		query[i] = { {l,r}, i };
	}
	while (B * B <= N) B++;
	B--;
	sort(query, query + M, cmp);

	int l = query[0].first.first, r = query[0].first.second, idx = query[0].second;

	for (int i = l; i <= r; i++) push(i);
	ans[idx] = cnt;

	for (int i = 1; i < M; i++) {
		int nl = query[i].first.first, nr = query[i].first.second;
		idx = query[i].second;

		while (l < nl) pop(l++);
		while (l > nl) push(--l);
		while (r < nr) push(++r);
		while (r > nr) pop(r--);

		ans[idx] = cnt;
	}

	for (int i = 0; i < M; i++) cout << ans[i] << '\n';
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

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
	return a.first.first / B < b.first.first / B;
}

void push(int a) {
	a = arr[a];
	cnt += fenwick_query(min(SZ, a + K)) - fenwick_query(max(1LL, a - K) - 1);
	update(a, 1);
	return;
}

void pop(int a) {
	a = arr[a];
	update(a, -1);
	cnt -= fenwick_query(min(SZ, a + K)) - fenwick_query(max(1LL, a - K) - 1);
	return;
}

void update(int pos, ll val) {
	while (pos < SZ) {
		tree[pos] += val;
		pos += (pos & -pos);
	}
}

ll fenwick_query(int idx) {
	ll ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}