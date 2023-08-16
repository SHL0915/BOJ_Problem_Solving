#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

ll A, B;
ll dp[505][50005];
ll psum[505];

void solve() {
    cin >> A >> B;

    ll ans = 0;
    for (int i = 1; i <= 500; i++) {
        if (A < psum[i] - B - 1) continue;
        if (psum[i] - B - 1 < 0) ans += dp[i][A];
        else ans += dp[i][A] - dp[i][max(0LL, psum[i] - B - 1)];
        ans %= mod;
    }

    cout << ans << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;

    for (int i = 1; i <= 500; i++) psum[i] = psum[i - 1] + i;

    dp[0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 0; j <= 50000; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j >= i) dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= mod;
        }
    }

    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 50000; j++) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    }

    while (t--) solve();
    return 0;
}