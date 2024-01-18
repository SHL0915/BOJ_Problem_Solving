#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int H, W;
ll dp[3005][3005];

ll DP(int h, int w) {
    if (h < 0 || w < 0) return 0;
    if (h == 0 || w == 0) return 1;
    ll &ret = dp[h][w];
    if (ret != -1) return ret;
    ret = 0;
    
    ret += (w * (h - 1) * DP(h - 2, w - 1)) % mod;
    ret %= mod;
    ret += (w * (w - 1) / 2 * DP(h - 1, w - 2)) % mod;
    ret %= mod;
    ret += 4 * w * DP(h - 1, w - 1) % mod;
    ret %= mod;
    ret += DP(h - 1, w) % mod;
    ret %= mod;
    
    return ret;
}

void solve() {
    cin >> H >> W;
    memset(dp, -1, sizeof(dp));
    
    cout << (DP(H, W) + (mod - 1)) % mod;
    
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