#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

ll N, ans = 1;
ll sum_tree[400005], num_tree[400005];

void update_num(int pos, ll val);
void update_sum(int pos, ll val);
ll query_num(int left, int right);
ll query_sum(int left, int right);

void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ll a; cin >> a;
		if (i == 1) {
			update_num(a, 1);
			update_sum(a, a);
			continue;
		}
		ll val = 0;
		ll num = query_num(0, a + 1);
		ll sum = query_sum(0, a + 1);
		val += (a * num - sum);
		val %= mod;
		num = query_num(a + 1, 200001);
		sum = query_sum(a + 1, 200001);
		val += (sum - a * num);
		val %= mod;
		ans = (ans * val) % mod;
		update_num(a, 1);
		update_sum(a, a);
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

void update_num(int pos, ll val) {
	for (num_tree[pos += 200000] += val; pos > 1; pos >>= 1) num_tree[pos >> 1] = num_tree[pos] + num_tree[pos ^ 1];
	return;
}

void update_sum(int pos, ll val) {
	for (sum_tree[pos += 200000] += val; pos > 1; pos >>= 1) sum_tree[pos >> 1] = sum_tree[pos] + sum_tree[pos ^ 1];
	return;
}

ll query_num(int left, int right) {
	ll ret = 0;
	for (left += 200000, right += 200000; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += num_tree[left++];
		if (right & 1) ret += num_tree[--right];
	}
	return ret;
}

ll query_sum(int left, int right) {
	ll ret = 0;
	for (left += 200000, right += 200000; left < right; left >>= 1, right >>= 1) {
		if (left & 1) ret += sum_tree[left++];
		if (right & 1) ret += sum_tree[--right];
	}
	return ret;
}