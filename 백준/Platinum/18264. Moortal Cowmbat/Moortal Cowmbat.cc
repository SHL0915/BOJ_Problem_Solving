#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, K;
string S;
int arr[1000005];
int adj[26][26];
int psum[1000005][26];
int dp[1000005][26];
int ans[1000005];

void solve() {
    cin >> N >> M >> K;
    cin >> S;
    for (int i = 1; i <= N; i++) arr[i] = S[i - 1] - 'a';

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) cin >> adj[i][j];
    }

    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) psum[i][j] = adj[arr[i]][j] + psum[i - 1][j];
    }

    memset(dp, INF, sizeof(dp));
    memset(ans, INF, sizeof(ans));
    ans[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + adj[arr[i]][j]);
            if (i >= K) dp[i][j] = min(dp[i][j], ans[i - K] + psum[i][j] - psum[i - K][j]);
            ans[i] = min(ans[i], dp[i][j]);
        }
    }

    cout << ans[N];
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