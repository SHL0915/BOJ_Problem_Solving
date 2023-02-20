#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
pii arr[200001];
vector <int> val;
ll tree[400005], psum[400005];

void update_tree(int pos, ll val);
void update_psum(int pos, ll val);
ll query_tree(int left, int right);
ll query_psum(int left, int right);
bool cmp(pii a, pii b);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		val.push_back(arr[i].second);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	sort(arr, arr + N);
	ll ans = 0;
	int i = 0, prev = 0;
	while (i < N) {
		if (i != 0 && arr[i].first != arr[i - 1].first) {
			for (int j = prev; j < i; j++) {
				int now = lower_bound(val.begin(), val.end(), arr[j].second) - val.begin() + 1;
				update_psum(now, query_tree(now + 1, N + 1));
				update_tree(now, 1);
			}
			prev = i;
		}
		int now = lower_bound(val.begin(), val.end(), arr[i].second) - val.begin() + 1;
		ans += query_psum(1, now);
		ans %= mod;		
		i++;
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

void update_tree(int pos, ll val) {
	pos += N;
	tree[pos] += val;
	tree[pos] %= mod;
	for (; pos > 1; pos >>= 1) tree[pos >> 1] = (tree[pos] + tree[pos ^ 1]) % mod;
	return;
}

void update_psum(int pos, ll val) {
	pos += N;
	psum[pos] += val;
	psum[pos] %= mod;
	for (; pos > 1; pos >>= 1) psum[pos >> 1] = (psum[pos] + psum[pos ^ 1]) % mod;
	return;
}

ll query_tree(int left, int right) {
	ll ret = 0;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left % 2) ret = (ret + tree[left++]) % mod;
		if (right % 2) ret = (ret + tree[--right]) % mod;
	}
	return ret;
}

ll query_psum(int left, int right) {
	ll ret = 0;
	for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
		if (left % 2) ret = (ret + psum[left++]) % mod;
		if (right % 2) ret = (ret + psum[--right]) % mod;
	}
	return ret;
}

bool cmp(pii a, pii b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}