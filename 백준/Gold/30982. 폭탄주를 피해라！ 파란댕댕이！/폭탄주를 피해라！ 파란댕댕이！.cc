#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, T, P;
int arr[105];
int dp[105][100005];

void solve() {
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cin >> P;

    dp[P][0] = 1;
    for (int i = P - 1; i >= 1; i--) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] |= dp[i + 1][j];
            if (arr[i] + j > M) break;
            dp[i][arr[i] + j] |= dp[i + 1][j];
        }
    }

    for (int i = P + 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] |= dp[i - 1][j];
            if (arr[i] + j > M) break;
            dp[i][arr[i] + j] |= dp[i - 1][j];
        }
    }

    int tot = M - arr[P];
    int max_t = T + 1;

    for (int i = 0; i <= tot; i++) {
        int a = T + 1, b = T + 1;
        for (int j = 1; j <= P; j++) if (dp[j][i] == 1) a = min(a, P - j);
        for (int j = P; j <= N; j++) if (dp[j][tot - i] == 1) b = min(b, j - P);
        max_t = min(max_t, min(a, b) * 2 + max(a, b));
    }

    if (max_t <= T) cout << "YES";
    else cout << "NO";

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