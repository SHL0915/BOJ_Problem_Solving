#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 1e9 + 7;
const ll sz = 200005;

int N;
pii arr[100005];
ll seg[sz * 4];
pii lazy[sz * 4];

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

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < sz * 4; i++) lazy[i] = {0, 1};

    sort(arr + 1, arr + 1 + N);
    update(1, 0, 2 * N, 0, 0, 1, 1);

    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        int l = arr[i].first, r = arr[i].second;

        ans *= 2;
        ans += query(1, 0, 2 * N, 0, l - 1);
        ans %= mod;

        ll q = query(1, 0, 2 * N, 0, r);
        update(1, 0, 2 * N, r, r, q, 1);
        update(1, 0, 2 * N, r + 1, 2 * N, 0, 2);
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