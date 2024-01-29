#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, M, K;
ll dp[1000005], psum[1000005];

void solve() {
    cin >> N >> M >> K;

    ll tot = 1;
    dp[0] = 0;
    psum[0] = 0;

    for (int i = 1; i <= N; i++) {
        tot *= M;
        tot %= mod;
        if (i - (K - 1) <= 0) {
            dp[i] = ((M - 1) * psum[i - 1]) % mod;
            dp[i] += M;
            dp[i] %= mod;
        } else dp[i] = ((M - 1) * ((psum[i - 1] - psum[i - K] + mod) % mod)) % mod;
        psum[i] = (dp[i] + psum[i - 1]) % mod;
    }

    cout << (tot - dp[N] + mod) % mod;

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