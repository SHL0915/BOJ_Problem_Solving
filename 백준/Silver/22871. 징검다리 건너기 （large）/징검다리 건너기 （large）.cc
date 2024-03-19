#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[5005];
int dp[5005];

int DP(int now, int k) {
    if (now == N - 1) return 1;
    int &ret = dp[now];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int i = now + 1; i < N; i++) {
        ll cost = (i - now) * (abs(arr[i] - arr[now]) + 1);
        if (cost <= k) ret |= DP(i, k);
    }
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    int l = 0, r = 10000005;
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        memset(dp, -1, sizeof(dp));
        if (DP(0, m)) {
            r = m - 1;
            ans = m;
        } else l = m + 1;
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