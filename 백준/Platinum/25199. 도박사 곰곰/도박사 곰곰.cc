#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, M;
int cnt[1005];
ll dp[1005][1005];
ll psum[1005][1005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    pii score = {0, 0};
    for (int i = 1; i <= M; i++) {
        if (cnt[i] >= score.first) score = {cnt[i], i};
    }

    dp[0][0] = 1;
    for (int i = 0; i <= N; i++) psum[0][i] = 1;

    for (int i = 1; i <= M; i++) {
        if (i == score.second) score.first--;
        for (int j = 0; j <= N; j++) {
            if (j <= score.first) dp[i][j] = psum[i - 1][j];
            else dp[i][j] = (psum[i - 1][j] - psum[i - 1][j - score.first - 1] + mod) % mod;
        }
        psum[i][0] = dp[i][0];
        for (int j = 1; j <= N; j++) psum[i][j] = (dp[i][j] + psum[i][j - 1]) % mod;
    }

    cout << dp[M][N];
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