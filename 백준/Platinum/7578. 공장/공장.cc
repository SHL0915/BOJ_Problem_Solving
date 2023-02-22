#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int idx[1000001];
vector <ll> tree;

void update(int pos, ll val);
ll query(int left, int right);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		idx[a] = i;
	}
	tree.resize(4 * N);
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		int pos = idx[a];
		ans += query(pos + 1, N + 1);
		update(pos, 1);
	}
	cout << ans;
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
	for (tree[pos += N] += val; pos > 1; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
	return;
}

ll query(int left, int right) {
	ll ret = 0;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += tree[left++];
		if (right & 1) ret += tree[--right];
	}
	return ret;
}