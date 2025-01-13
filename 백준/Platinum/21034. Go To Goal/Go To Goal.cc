#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, M;
ll fact[300005], ifact[300005];

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

ll nCm(ll n, ll m) {
    return ((fact[n] * ifact[m]) % mod * ifact[n - m]) % mod;
}

void solve() {
    cin >> N >> M;
    
    fact[0] = 1;
    for (int i = 1; i <= 300000; i++) fact[i] = (fact[i - 1] * i) % mod;
    
    ifact[300000] = inv(fact[300000]);
    for (int i = 299999; i >= 0; i--) ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    
    ll ans = 0;
    for (int i = 0; i <= N / 2; i++) {
        ll a = i * 2, b = i, c = N - a, d = c, e = M - (b + d);
        if (e < 0) continue;
        ll ret = fact[b + c + e];
        ret *= ifact[b], ret %= mod;
        ret *= ifact[c], ret %= mod;
        ret *= ifact[e], ret %= mod;
        ans += ret;
        ans %= mod;
    }
    
    N--;
    for (int i = 0; i <= N / 2; i++) {
        ll a = i * 2, b = i, c = N - a, d = c, e = M - (b + d);
        if (e < 0) continue;
        ll ret = fact[b + c + e];
        ret *= ifact[b], ret %= mod;
        ret *= ifact[c], ret %= mod;
        ret *= ifact[e], ret %= mod;
        ans += ret;
        ans %= mod;
    }
    
    N--;
    for (int i = 0; i <= N / 2; i++) {
        ll a = i * 2, b = i, c = N - a, d = c, e = M - (b + d);
        if (e < 0) continue;
        ll ret = fact[b + c + e];
        ret *= ifact[b], ret %= mod;
        ret *= ifact[c], ret %= mod;
        ret *= ifact[e], ret %= mod;
        ans += ret;
        ans %= mod;
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