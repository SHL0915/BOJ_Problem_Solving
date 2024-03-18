#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;

int N, X, Y;
pii arr[55];
int dp[55][105][105];

int DP(int now, int x, int y) {
    if (now == 0) {
        if (x == X && y == Y) return 0;
        else return INF;
    }
    int &ret = dp[now][x][y];
    if (ret != -1) return ret;
    ret = INF;
    ret = min(ret, DP(now - 1, x, y));
    ret = min(ret, 1 + DP(now - 1, min(X, x + arr[now].first), min(Y, y + arr[now].second)));
    return ret;
}

void solve() {
    cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    memset(dp, -1, sizeof(dp));
    
    int ans = INF;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, DP(i, 0, 0));
    }
    
    if (ans == INF) cout << -1;
    else {
        cout << ans << '\n';
        for (int i = 1; i <= N; i++) {
            if (DP(i, 0, 0) == ans) {
                cout << i;
                return;
            }
        }
    }
    
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