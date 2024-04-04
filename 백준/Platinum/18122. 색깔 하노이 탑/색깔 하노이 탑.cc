#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N;
ll dp[1000005];

ll DP(int now) {
    if (now == 0) return 0;
    ll &ret = dp[now];
    if (ret != -1) return ret;
    return ret = (DP(now - 1) * 2 + 2) % mod;
}

void solve() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    
    cout << (4 * DP(N - 1) + 3) % mod;
    
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