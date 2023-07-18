#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int L, G;
ll arr[8005], psum[8005], dp[805][8005];

ll cal(int i, int j) {
    return (psum[i] - psum[j]) * (i - j);
}

void DNC(int t, int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    int idx;
    for (int i = l; i <= min(m, r); i++) {
        if (dp[t][m] > dp[t - 1][i] + cal(m, i)) {
            dp[t][m] = dp[t - 1][i] + cal(m, i);
            idx = i;
        }
    }

    DNC(t, s, m - 1, l, idx);
    DNC(t, m + 1, e, idx, r);
    return;
}

void solve() {
    cin >> L >> G;
    for (int i = 1; i <= L; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    memset(dp, INF, sizeof(dp));

    for (int i = 1; i <= L; i++) dp[1][i] = psum[i] * i;
    for (int i = 2; i <= G; i++) DNC(i, 1, L, 1, L);

    cout << dp[G][L];

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