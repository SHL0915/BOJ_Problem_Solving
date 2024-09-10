#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

ll N, K;
ll dp[55], comb[55][55];

ll _pow(ll n, ll k) {
    n %= mod;
    ll ret = 1;
    while (k) {
        if (k % 2) ret = (ret * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }
    return ret;
}

ll inv(ll n) {
    return _pow(n, mod - 2);
}

ll nCk(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    ll &ret = comb[n][k];
    if (~ret) return ret;
    ret = (nCk(n - 1, k) + nCk(n - 1, k - 1)) % mod;
    return ret;
}

ll DP(int n) {
    if (!n) return N % mod;
    ll &ret = dp[n];
    if (~ret) return ret;
    ret = (_pow(N + 1, n + 1) - 1 + mod) % mod;
    
    for (int i = 2; i <= n + 1; i++) ret = (ret + mod - (nCk(n + 1, i) * DP(n - i + 1)) % mod) % mod;
    
    ret *= inv(n + 1);
    ret %= mod;
    
    return ret;
}

void solve() {
    cin >> N >> K;
    memset(comb, -1, sizeof(comb));
    memset(dp, -1, sizeof(dp));
    cout << DP(K);
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