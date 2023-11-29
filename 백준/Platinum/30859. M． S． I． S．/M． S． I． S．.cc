#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
pii arr[10005];
int dp[10005][10005];

void solve() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) cin >> arr[i].first;
    for (int i = 1; i <= N; i++) cin >> arr[i].second;
    sort(arr, arr + N + 1);
    
    int ans = 0;
    memset(dp, -INF, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + max(arr[i].first, arr[i].second));
            if (arr[i].second >= arr[j].second)
                dp[i + 1][i] = max(dp[i + 1][i], arr[i].first + arr[i].second + dp[i][j]);
        }
    }
    
    for (int i = 0; i <= N; i++) ans = max(ans, dp[N + 1][i]);
    
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