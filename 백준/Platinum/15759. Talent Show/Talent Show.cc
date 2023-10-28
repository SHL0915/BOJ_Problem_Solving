#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, W;
pii arr[255];
double dp[255][1005];

void solve() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

    double l = 0, r = 1000000;
    int cnt = 100;
    while (cnt--) {
        double m = (l + r) / 2.0;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= W; j++) dp[i][j] = -1e10;
        }

        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= W; j++) {
                if (dp[i - 1][j] == -1e10) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                int nxt = min(W, j + arr[i].first);
                double val = arr[i].second - m * arr[i].first;
                dp[i][nxt] = max(dp[i][nxt], dp[i - 1][j] + val);
            }
        }

        if (dp[N][W] >= 0) l = m;
        else r = m;
    }

    int ans = ((l + r) / 2.0 * 1000);

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