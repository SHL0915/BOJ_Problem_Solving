#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[55];
int dp[51][5000001];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

    memset(dp, 0x3f, sizeof(dp));

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 5000000; j++) {
            if (j >= arr[i].first) dp[i][j] = min(dp[i][j], dp[i - 1][j - arr[i].first]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i].second);
        }
    }

    int ans = 1e9;
    for (int i = 0; i <= 5000000; i++) ans = min(ans, max(i, dp[N][i]));

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