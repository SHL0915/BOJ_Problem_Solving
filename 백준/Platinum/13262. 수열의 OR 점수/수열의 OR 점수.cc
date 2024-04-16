#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int arr[5005];
ll dp[2][5005];
int cost[5005][5005];

void dnc(int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    dp[1][m] = -1;
    int idx = -1;
    for (int i = l; i <= min(m, r); i++) {
        if (dp[1][m] < dp[0][i] + cost[i + 1][m]) {
            dp[1][m] = dp[0][i] + cost[i + 1][m];
            idx = i;
        }
    }
    if (s != e) {
        dnc(s, m - 1, l, idx);
        dnc(m + 1, e, idx, r);
    }
    return;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            cost[i][j] = cost[i][j - 1] | arr[j];
        }
    }
    
    for (int i = 1; i <= N; i++) dp[0][i] = cost[1][i];
    for (int i = 2; i <= K; i++) dnc(1, N, 1, N), swap(dp[0], dp[1]);
    
    cout << dp[0][N];
    
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