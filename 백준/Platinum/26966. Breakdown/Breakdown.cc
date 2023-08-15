#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, K;
ll W[305][305];
vector<pii> edge;
ll ans[305 * 305];
ll dp1[305][5], dp2[305][5], dp3[305][305][3];

void add_edge(int a, int b) {
    dp3[a][b][1] = min(dp3[a][b][1], W[a][b]);
    for (int i = 1; i <= N; i++) dp3[a][i][2] = min(dp3[a][i][2], W[a][b] + dp3[b][i][1]);
    for (int i = 1; i <= N; i++) dp3[i][b][2] = min(dp3[i][b][2], dp3[i][a][1] + W[a][b]);

    for (int i = 1; i <= N; i++) {
        dp1[i][1] = min(dp1[i][1], dp3[1][i][1]);
        dp2[i][1] = min(dp2[i][1], dp3[i][N][1]);
    }

    for (int i = 1; i <= N; i++) {
        dp1[i][2] = min(dp1[i][2], dp3[1][i][2]);
        dp2[i][2] = min(dp2[i][2], dp3[i][N][2]);
    }

    for (int i = 1; i <= N; i++) {
        dp1[i][3] = min(dp1[i][3], dp1[a][1] + W[a][b] + dp3[b][i][1]);
        dp2[i][3] = min(dp2[i][3], dp3[i][a][1] + W[a][b] + dp2[b][1]);

        if (a == 1) dp1[i][3] = min(dp1[i][3], W[a][b] + dp3[b][i][2]);
        if (a == i) dp2[i][3] = min(dp2[i][3], W[a][b] + dp3[b][N][2]);

        if (b == i) dp1[i][3] = min(dp1[i][3], dp1[a][2] + W[a][b]);
        if (b == N) dp2[i][3] = min(dp2[i][3], dp3[i][a][2] + W[a][b]);
    }

    for (int i = 1; i <= N; i++) {
        dp1[i][4] = min(dp1[i][4], dp1[a][1] + W[a][b] + dp3[b][i][2]);
        dp1[i][4] = min(dp1[i][4], dp1[a][2] + W[a][b] + dp3[b][i][1]);
        dp2[i][4] = min(dp2[i][4], dp3[i][a][1] + W[a][b] + dp2[b][2]);
        dp2[i][4] = min(dp2[i][4], dp3[i][a][2] + W[a][b] + dp2[b][1]);

        if (a == 1) {
            for (int j = 1; j <= N; j++) dp1[i][4] = min(dp1[i][4], W[a][b] + dp3[b][j][2] + dp3[j][i][1]);
        }
        if (a == i) dp2[i][4] = min(dp2[i][4], W[a][b] + dp2[b][3]);

        if (b == i) dp1[i][4] = min(dp1[i][4], dp1[a][3] + W[a][b]);
        if (b == N) {
            for (int j = 1; j <= N; j++) dp2[i][4] = min(dp2[i][4], dp3[i][j][2] + dp3[j][a][1] + W[a][b]);
        }
    }


}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> W[i][j];
    }

    for (int i = 0; i < N * N; i++) {
        int a, b;
        cin >> a >> b;
        edge.emplace_back(a, b);
    }

    reverse(edge.begin(), edge.end());

    memset(dp1, INF, sizeof(dp1));
    memset(dp2, INF, sizeof(dp2));
    memset(dp3, INF, sizeof(dp3));

    for (int i = 0; i < edge.size(); i++) {
        ll now = INF;
        for (int j = 1; j <= N; j++) {
            int half = K / 2;
            now = min(now, dp1[j][half] + dp2[j][K - half]);
        }

        if (now == INF) ans[i] = -1;
        else ans[i] = now;

        int a = edge[i].first, b = edge[i].second;
        add_edge(a, b);
    }

    for (int i = N * N - 1; i >= 0; i--) cout << ans[i] << '\n';
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