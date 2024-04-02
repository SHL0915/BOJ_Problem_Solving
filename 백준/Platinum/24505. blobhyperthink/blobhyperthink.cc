#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
const int sz = 100005;

int N;
ll arr[100005];

void update(int pos, ll v, vector<ll> &seg) {
    for (seg[pos += sz] += v; pos > 0; pos >>= 1) seg[pos >> 1] = (seg[pos] + seg[pos ^ 1]) % mod;
    return;
}

ll query(int l, int r, vector<ll> &seg) {
    r++;
    ll ret = 0;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++], ret %= mod;
        if (r & 1) ret += seg[--r], ret %= mod;
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    vector<ll> seg[15];
    for (int i = 0; i < 15; i++) seg[i].resize(2 * sz + 5);
    
    update(0, 1, seg[0]);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 11; j >= 1; j--) {
            ll q = query(0, arr[i] - 1, seg[j - 1]);
            if (j == 11) ans += q, ans %= mod;
            update(arr[i], q, seg[j]);
        }
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