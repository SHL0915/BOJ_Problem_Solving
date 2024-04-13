#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int L, G;
ll C[8005];
ll psum[8005];
ll dp[805][8005];

ll cost(int l, int r) {
    return (r - l + 1) * (psum[r] - psum[l - 1]);
}

void dnc(int i, int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    int idx = -1;

    for (int k = l; k <= min(m, r); k++) {
        //if (k + 1 > m) continue;
        if (dp[i][m] > dp[i - 1][k] + cost(k + 1, m)) {
            dp[i][m] = dp[i - 1][k] + cost(k + 1, m);
            idx = k;
        }
    }

    dnc(i, s, m - 1, l, idx);
    dnc(i, m + 1, e, idx, r);
    return;
}

void solve() {
    cin >> L >> G;
    for (int i = 1; i <= L; i++) cin >> C[i], psum[i] = psum[i - 1] + C[i];

    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= L; i++) dp[0][i] = cost(1, i);
    for (int i = 1; i < G; i++) dnc(i, 1, L, 1, L);

    cout << dp[G - 1][L];
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