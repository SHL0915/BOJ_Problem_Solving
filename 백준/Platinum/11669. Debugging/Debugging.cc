#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, R, P;
ll dp[1000005];

ll DP(int n) {
    if (n == 1) return 0;
    ll &ret = dp[n];
    if (ret != -1) return ret;
    ret = INF;

    for (ll i = 2; i <= n; i++) {
        if (n % i) ret = min(ret, R + DP(n / i + 1) + (i - 1) * P);
        else ret = min(ret, R + DP(n / i) + (i - 1) * P);
    }

    return ret;
}

void solve() {
    cin >> N >> R >> P;
    memset(dp, -1, sizeof(dp));
    cout << DP(N);
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