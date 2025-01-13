#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, H;
pii arr[105];
ll dp[105][100005];

void solve() {
    cin >> N >> H;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    
    for (int i = 1; i <= N; i++) {
        ll a = arr[i].first, b = arr[i].second, c = 0, d = 0;
        while (b) {
            c += a;
            d += (b + 1) / 2;
            for (int j = 0; j <= 10000; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j >= d) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - d] + c);
                }
            }
            b /= 2;
            a *= 2;
        }
    }
    
    ll ans = 1e9;
    for (int i = 0; i <= 10000; i++) {
        if (dp[N][i] >= H) ans = min(ans, (ll) i);
    }
    
    if (ans == 1e9) cout << -1;
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