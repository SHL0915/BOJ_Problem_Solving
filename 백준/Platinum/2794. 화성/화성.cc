#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K;
ll adj[1 << 9][1 << 9];
ll dp[1 << 9][1 << 9];

ll DP(int now, int p) {
    if (now == (1 << K)) return 0;
    ll &ret = dp[now][p];
    if (ret != -1) return ret;
    ret = 1e17;
    
    int bit = -1, nxt = 0;
    for (int i = 10; i >= 0; i--) {
        int a = now & (1 << i), b = (now - 1) & (1 << i);
        if (a != b) {
            bit = i;
            if (!(p & (1 << i))) nxt += (1 << i);
            break;
        } else nxt += p & (1 << i);
    }
    
    for (int i = 0; i < (1 << bit); i++) {
        ll cost = adj[p][nxt + i];
        ret = min(ret, cost + DP(now + 1, nxt + i));
    }
    
    return ret;
}

void solve() {
    cin >> K;
    for (int i = 0; i < (1 << K); i++) {
        for (int j = 0; j < (1 << K); j++) cin >> adj[i][j];
    }
    
    memset(dp, -1, sizeof(dp));
    ll ans = 1e17;
    
    for (int i = 0; i < (1 << K); i++) ans = min(ans, DP(1, i));
    
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