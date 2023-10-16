#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, S;
int W[1005], T[1005], graph[1005], vst[1005];
vector<pii> chain[1005];
int dp[1005][100005];

void solve() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> W[i];
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        if (a) graph[a] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (vst[i]) continue;
        int a = 0, b = 0;
        int now = i;
        while (1) {
            vst[now] = 1;
            a += W[now];
            b += T[now];
            chain[i].push_back({a, b});
            if (graph[now] == 0) break;
            else now = graph[now];
        }
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (dp[i - 1][j] == INF) continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            for (pii a: chain[i]) dp[i][min(S, j + a.first)] = min(dp[i][min(S, j + a.first)], dp[i - 1][j] + a.second);
        }
    }

    int ans = dp[N][S];
    if (ans == INF) cout << -1;
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