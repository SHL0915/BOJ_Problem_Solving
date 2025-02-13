#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, K;
ll dp[3005];

ll DP(int now) {
    if (now > N) return 0;
    if (now == N) return 1;
    ll &ret = dp[now];
    if (~ret) return ret;
    ret = 1;
    for (int i = now + 2; i <= N; i++) {
        ret += 2 * DP(i);
        ret %= mod;
    }
    return ret;
}

void solve() {
    cin >> N >> K;
    
    memset(dp, -1, sizeof(dp));
    
    ll ans = 0;
    if (K != 1) {
        ans += 2 * DP(K + 1) % mod;
        for (int i = K; i >= 3; i--) ans += DP(i), ans %= mod;
    } else ans += DP(2);
    
    for (int i = 3; i <= N; i++) ans += DP(i), ans %= mod;
    
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