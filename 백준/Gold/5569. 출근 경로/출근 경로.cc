#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 100000;

int W, H;
ll dp[105][105][2][2];

ll DP(int x, int y, int dir, int turn) {
    if (x > W || y > H) return 0;
    if (x == W && y == H) return 1;
    ll &ret = dp[x][y][turn][dir];
    if (ret != -1) return ret;
    ret = 0;

    if (turn) {
        if (dir) ret += DP(x, y + 1, dir, 0), ret %= mod;
        else ret += DP(x + 1, y, dir, 0), ret %= mod;
    } else {
        if (dir) {
            ret += DP(x, y + 1, dir, 0), ret %= mod;
            ret += DP(x + 1, y, dir ^ 1, 1), ret %= mod;
        } else {
            ret += DP(x + 1, y, dir, 0), ret %= mod;
            ret += DP(x, y + 1, dir ^ 1, 1), ret %= mod;
        }
    }

    return ret;
}

void solve() {
    cin >> W >> H;
    memset(dp, -1, sizeof(dp));

    ll ans = DP(1, 2, 1, 0) + DP(2, 1, 0, 0);
    ans %= mod;

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