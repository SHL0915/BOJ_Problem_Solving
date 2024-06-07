#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
ll arr[200005];
ll dp[200005];

ll DP(int now, int k) {
    if (now >= N) return 0;
    ll &ret = dp[now];
    if (ret != -1) return ret;
    ret = 0;
    ret = max(ret, DP(now + 1, k));
    ret = max(ret, arr[now] + DP(now + (k + 1), k));
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    int l = 0, r = N, ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        memset(dp, -1, sizeof(dp));
        ll v = DP(0, m);
        if (v >= M) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }
    
    if (ans >= N) cout << "Free!";
    else cout << ans;
    
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