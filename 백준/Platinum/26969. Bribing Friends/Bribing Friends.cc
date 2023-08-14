#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct cow {
    int X, P, C;

    bool operator<(const cow cmp) const {
        return X < cmp.X;
    }
};

int N, A, B;
cow arr[2005];
ll dp[2005][2];

void solve() {
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) cin >> arr[i].P >> arr[i].C >> arr[i].X;
    sort(arr + 1, arr + N + 1);

    memset(dp, -INF, sizeof(dp));
    dp[B][0] = 0;
    dp[A][1] = 0;

    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= A; j++) {
            if (j >= arr[i].C) {
                dp[j - arr[i].C][1] = max(dp[j - arr[i].C][1], dp[j][1] + arr[i].P);
                ans = max(ans, dp[j - arr[i].C][1]);
            }
        }
        for (int j = 0; j <= B; j++) {
            int d = min(arr[i].C, j / arr[i].X);
            if (d == arr[i].C) {
                dp[j - d * arr[i].X][0] = max(dp[j - d * arr[i].X][0], dp[j][0] + arr[i].P);
                ans = max(ans, dp[j - d * arr[i].X][0]);
            } else {
                if (A >= (arr[i].C - d)) {
                    dp[A - (arr[i].C - d)][1] = max(dp[A - (arr[i].C - d)][1], dp[j][0] + arr[i].P);
                    ans = max(ans, dp[A - (arr[i].C - d)][1]);
                }
            }
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