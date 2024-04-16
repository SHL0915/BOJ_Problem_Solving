#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1e18;

int N, K;
ll arr[4005][4005];
ll psum[4005][4005];
ll cost[4005][4005];
ll dp[805][4005];

void DP(int i, int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) / 2;
    pii M = {INF, -1};

    for (int k = optl; k <= min(m, optr); k++) {
        if (k + 1 > m) continue;
        M = min(M, {dp[i - 1][k] + cost[k + 1][m], k});
    }

    dp[i][m] = M.first;
    int opt = M.second;
    
    if(l != r) {
    DP(i, l, m - 1, optl, opt);
    DP(i, m + 1, r, opt, optr);   
    }
    
    return;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> arr[i][j], psum[i][j] = psum[i][j - 1] + arr[i][j];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            cost[i][j] = cost[i][j - 1] + (psum[j][j - 1] - psum[j][i - 1]);
        }
    }

    for (int i = 1; i <= N; i++) dp[0][i] = cost[1][i];
    for (int i = 1; i < K; i++) {
        DP(i, 1, N, 0, N);
    }

    cout << dp[K - 1][N];

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