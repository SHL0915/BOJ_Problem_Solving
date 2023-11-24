#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, H, D, K;
int arr[25];
int dp[20][105][2][2];

int DP(int now, int dist, int t, int s) {
    if (now == N) return 0;
    int &ret = dp[now][dist][t][s];
    if (ret != -1) return ret;
    ret = INF;
    
    if(s == 0) {
        ret = min(ret, max(0, arr[now] - dist) / 2 + DP(now + 1, dist, t, 0));
        ret = min(ret, max(0, arr[now] - (dist + K)) + DP(now + 1, dist + K, t, 0));
        if (t == 0) ret = min(ret, max(0, arr[now] - dist) + DP(now + 1, dist, 1, 1));
    }
    else {
        ret = min(ret, DP(now + 1, dist, t, 0));
        ret = min(ret, DP(now + 1, dist + K, t, 0));
        if (t == 0) ret = min(ret, DP(now + 1, dist, 1, 1));
    }
    
    return ret;
}

void solve() {
    cin >> N >> H >> D >> K;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = H - DP(0, D, 0, 0);
    if (ans <= 0) cout << -1;
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