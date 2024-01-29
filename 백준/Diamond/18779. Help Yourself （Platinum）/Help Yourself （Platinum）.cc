#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 1e9 + 7;

struct lazy_seg {
    int sz;
    vector<ll> seg;
    vector<pii> lazy;

    lazy_seg(int n) {
        sz = n;
        seg.resize(4 * n, 0);
        lazy.resize(4 * n, {0, 1});
    }

    void update_lazy(int n, int s, int e) {
        ll &fi = lazy[n].first;
        ll &se = lazy[n].second;
        if (fi == 0 && se == 1) return;
        seg[n] = (seg[n] * se + (e - s + 1) * fi) % mod;
        if (s != e) {
            lazy[n * 2] = {(lazy[n * 2].first * se + fi) % mod, (lazy[n * 2].second * se) % mod};
            lazy[n * 2 + 1] = {(lazy[n * 2 + 1].first * se + fi) % mod, (lazy[n * 2 + 1].second * se) % mod};
        }
        fi = 0;
        se = 1;
        return;
    }

    void update(int n, int s, int e, int l, int r, ll sum, ll product) {
        update_lazy(n, s, e);
        if (l > e || r < s) return;
        if (l <= s && e <= r) {
            lazy[n].first *= product, lazy[n].first += sum, lazy[n].first %= mod;
            lazy[n].second *= product, lazy[n].second %= mod;
            update_lazy(n, s, e);
            return;
        }
        int m = (s + e) / 2;
        update(n * 2, s, m, l, r, sum, product);
        update(n * 2 + 1, m + 1, e, l, r, sum, product);
        seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % mod;
        return;
    }

    ll query(int n, int s, int e, int l, int r) {
        update_lazy(n, s, e);
        if (l > e || r < s) return 0;
        if (l <= s && e <= r) return seg[n];
        int m = (s + e) / 2;
        return (query(n * 2, s, m, l, r) + query(n * 2 + 1, m + 1, e, l, r)) % mod;
    }
};

int N, K;
pii arr[100005];
ll nCk[15][15], q[15];
vector<lazy_seg> seg;

ll comb(int n, int k) {
    if (k == 0 || k == n) return 1;
    ll &ret = nCk[n][k];
    if (ret != -1) return ret;
    ret = (comb(n - 1, k) + comb(n - 1, k - 1)) % mod;
    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr + 1, arr + 1 + N);
    int sz = 2 * N + 5;

    for (int i = 0; i < K; i++) seg.push_back(lazy_seg(sz));
    seg[0].update(1, 0, sz, 0, 0, 1, 1);

    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        int l = arr[i].first, r = arr[i].second;

        for (int k = 0; k < K; k++) q[k] = seg[k].query(1, 0, sz, 0, l - 1);

        ans *= 2;
        for (int k = 0; k < K; k++) ans += comb(K, k) * q[k], ans %= mod;
        ans %= mod;

        for (int k = 0; k < K; k++) {
            ll a = seg[k].query(1, 0, sz, l, r);
            for (int j = 0; j <= k; j++) a += comb(k, j) * q[j];
            a %= mod;

            seg[k].update(1, 0, sz, r, r, a, 1);
            seg[k].update(1, 0, sz, r + 1, sz, 0, 2);
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
    memset(nCk, -1, sizeof(nCk));
    //cin >> t;
    while (t--) solve();
    return 0;
}