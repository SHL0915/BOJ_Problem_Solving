#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, Q, U, V, a, b, c;
ll arr[1005];
ll dp[1005];

ll DP(int now) {
    if (now == c) return arr[now] * U;
    ll &ret = dp[now];
    if (ret >= -2e18) return ret;
    ret = arr[now] * U;
    ret = max(ret, arr[now] * U + V + DP(now + 1));
    return ret;
}

void solve() {
    cin >> N >> Q >> U >> V;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    while (Q--) {
        cin >> a >> b >> c;
        if (!a) {
            memset(dp, -0x3f, sizeof(dp));
            ll ans = -1e18;
            for (int i = b; i <= c; i++) ans = max(ans, DP(i));
            cout << ans << '\n';
        } else arr[b] = c;
    }

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