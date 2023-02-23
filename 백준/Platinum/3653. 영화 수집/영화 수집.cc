#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, idx, sz;
int pos[400005];
int tree[400005];

void update(int pos, int val);
int query(int left, int right);

void solve() {
	memset(pos, 0, sizeof(pos));
	memset(tree, 0, sizeof(tree));
	cin >> N >> M;
	idx = M;
	sz = N + M;
	for (int i = M + 1; i <= M + N; i++) {
		update(i, 1);
		pos[i - M] = i;
	}
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		cout << query(1, pos[a]) << ' ';
		update(pos[a], -1);
		pos[a] = idx--;
		update(pos[a], 1);
	}
	cout << '\n';
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

void update(int pos, int val) {
	for (tree[pos += sz] += val; pos > 1; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
	return;
}

int query(int left, int right) {
	int ret = 0;
	for (left += sz, right += sz; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += tree[left++];
		if (right & 1) ret += tree[--right];
	}
	return ret;
}