#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, T;
pii arr[1005];
ll dp[1005][1005];

void solve() {
    cin >> N >> T;
    
    ll tot = 0;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second, tot += arr[i].second;
    
    memset(dp, -0x3f, sizeof(dp));
    
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j < arr[i].first) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].first] + arr[i].second);
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= T; i++) ans = max(ans, dp[N][i]);
    
    cout << tot - ans;
    
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