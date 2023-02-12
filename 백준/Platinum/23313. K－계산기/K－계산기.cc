#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
ll arr[500001];
int parent[500001];
int oper[500001];
int num[500001];
vector <ll> tree;

int Find(int a);
void Union(int a, int b);
int BinarySearch(int left, int right, int k);
void update(int pos, ll val);
ll query(int left, int right);
ll rev(ll a);

void solve() {
	cin >> N;
	tree.resize(4 * N);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		update(i, 1);
	}
	for (int i = 1; i <= N - 1; i++) {
		char c;
		cin >> arr[i] >> c;
		if (c == '+') oper[i] = 0;
		else if (c == '-') oper[i] = 1;
		else if (c == '*') oper[i] = 2;
		else oper[i] = 3;
	}
	cin >> arr[N];
	for (int i = 1; i <= N - 1; i++) cin >> num[i];
	ll res = 0;
	for (int i = 1; i <= N - 1; i++) {
		res ^= num[i];
		int idx = BinarySearch(1, N, res);
		if (query(1, idx + 1) < res) idx++;
		update(idx, -1);
		ll a = arr[Find(idx)];
		ll b = arr[Find(idx + 1)];
		ll c = oper[idx];
		if (c == 0) res = (a + b) % mod;
		else if (c == 1) res = (a - b + mod) % mod;
		else if (c == 2) res = (a * b) % mod;
		else res = (a * rev(b)) % mod;
		cout << res << '\n';
		Union(idx, idx + 1);
		arr[Find(idx)] = res;
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

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}

int BinarySearch(int left, int right, int k) {
	if (left < right) {
		int mid = (left + right) / 2;
		ll val = query(1, mid + 1);
		if (val >= k) return BinarySearch(left, mid - 1, k);
		else return BinarySearch(mid + 1, right, k);
	}
	else return left;
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

ll rev(ll a) {
	ll bit = 1, ret = 1;
	while (bit <= mod - 2) {
		if (bit & (mod - 2)) ret = (ret * a) % mod;
		bit <<= 1;
		a = (a * a) % mod;
	}
	ret %= mod;
	return ret;
}