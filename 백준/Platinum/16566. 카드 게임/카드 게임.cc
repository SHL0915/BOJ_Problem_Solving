#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int tree[16000001];

void update(int pos, int val);
int query(int left, int right);
int BinarySearch(int left, int right);

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		update(a, 1);
	}

	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		int ans = BinarySearch(a + 1, N);
		if (query(ans, ans + 1) == 0) ans++;
		cout << ans << '\n';
		update(ans, -1);
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

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		if (query(left, mid + 1)) return BinarySearch(left, mid - 1);
		else return BinarySearch(mid + 1, right);
	}
	else return left;
}

void update(int pos, int val) {
	for (tree[pos += N] += val; pos > 1; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
	return;
}

int query(int left, int right) {
	int ret = 0;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += tree[left++];
		if (right & 1) ret += tree[--right];
	}
	return ret;
}