#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f;;

int N;
ll arr[1000001];
ll fact[2000001];
ll inverse[2000001];
pii seg[2000505];

ll recur(ll l, ll r);
ll inv(ll a);
ll cat(ll a);
ll nCr(ll n, ll r);
void update(int pos, pii val);
pii query(int l, int r);

void solve() {
	cin >> N;
	for (int i = 1; i < 2000505; i++) seg[i] = { INF, INF };
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(i, { arr[i],i });
	}
	cout << recur(1, N);
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1;
	for (ll i = 1; i <= 2000000; i++) fact[i] = (fact[i - 1] * i) % mod;

	inverse[2000000] = inv(fact[2000000]);
	for (ll i = 1999999; i >= 0; i--) inverse[i] = (inverse[i + 1] * (i + 1)) % mod;

	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

ll recur(ll l, ll r) {
	if (l >= r) return 1;

	ll ret = 1, cnt = 0;
	pii val = query(l, r + 1);
	int idx = l;

	while (idx <= r) {
		pii next = query(idx, r + 1);
		if (next.first != val.first) {
			ret *= recur(idx, r);
			ret %= mod;
			break;
		}
		cnt++;
		ret *= recur(idx, next.second - 1);
		ret %= mod;
		idx = next.second + 1;
	}

	ret *= cat(cnt);
	ret %= mod;

	return ret;
}

ll inv(ll a) {
	ll bit = 1, ret = 1;
	while (bit <= mod - 2) {
		if (bit & (mod - 2)) ret = (ret * a) % mod;
		bit <<= 1;
		a = (a * a) % mod;
	}
	ret %= mod;
	return ret;
}

ll cat(ll a) {
	return (nCr(2 * a, a) * inv(a + 1)) % mod;
}

ll nCr(ll n, ll r) {
	return ((fact[n] * inverse[r]) % mod * inverse[n - r]) % mod;
}

void update(int pos, pii val) {
	for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = min(seg[pos], seg[pos ^ 1]);
	return;
}

pii query(int l, int r){
	pii ret = { INF, INF };
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = min(ret, seg[l++]);
		if (r & 1) ret = min(ret, seg[--r]);
	}
	return ret;
}