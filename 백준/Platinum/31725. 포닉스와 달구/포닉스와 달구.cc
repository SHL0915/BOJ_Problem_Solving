#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
ll arr[2005][2005];
ll dp[2005][2005], rev[2005][2005];
ll v[2005][2005], R[2005][2005], C[2005][2005];

ll DP(int x, int y) {
    if (x == N - 1 && y == N - 1) return arr[y][x];
    ll &ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;
    if (x < N - 1) ret = max(ret, arr[y][x] + DP(x + 1, y));
    if (y < N - 1) ret = max(ret, arr[y][x] + DP(x, y + 1));
    return ret;
}

ll REV(int x, int y) {
    if (x == 0 && y == 0) return arr[y][x];
    ll &ret = rev[y][x];
    if (ret != -1) return ret;
    ret = 0;
    if (x > 0) ret = max(ret, arr[y][x] + REV(x - 1, y));
    if (y > 0) ret = max(ret, arr[y][x] + REV(x, y - 1));
    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> arr[i][j];
    }
    
    memset(dp, -1, sizeof(dp));
    memset(rev, -1, sizeof(rev));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) v[i][j] = DP(j, i) + REV(j, i) - arr[i][j];
    }
    
    for (int i = 0; i < N; i++) {
        R[0][i] = v[0][i];
        C[i][0] = v[i][0];
        for (int j = 1; j < N; j++) {
            R[j][i] = max(v[j][i], R[j - 1][i]);
            C[i][j] = max(v[i][j], C[i][j - 1]);
        }
    }
    
    ll ans = 0x3f3f3f3f3f3f3f3fLL;
    for (int i = 0; i <= N - K; i++) {
        for (int j = 0; j <= N - K; j++) {
            if (i == 0 && j == 0) continue;
            if (i == N - K && j == N - K) continue;
            ll a = 0, b = 0;
            if (i && j < N - K) a = R[i - 1][j + K];
            if (j && i < N - K) b = C[i + K][j - 1];
            ans = min(ans, max(a, b));
        }
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