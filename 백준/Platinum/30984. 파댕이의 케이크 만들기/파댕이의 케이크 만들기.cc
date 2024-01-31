#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, K;
ll fact[2000005], invf[2000005];

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

ll nCr(ll n, ll r) {
    return ((fact[n] * invf[r]) % mod * invf[n - r]) % mod;
}

ll nHr(ll n, ll r) {
    return nCr(n + r - 1, r);
}

void solve() {
    cin >> N >> K;

    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        ans *= nHr(i, K), ans %= mod;
    }

    cout << inv(ans);
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= 2000000; i++) fact[i] = (fact[i - 1] * i) % mod;
    invf[2000000] = inv(fact[2000000]);
    for (int i = 1999999; i >= 0; i--) invf[i] = (invf[i + 1] * (i + 1)) % mod;

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}