#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, K;
ll dp[1005][1005];

ll DP(int one, int k) {
    if (k == 0) {
        if (!one) return 1;
        else return 0;
    }
    ll &ret = dp[one][k];
    if (~ret) return ret;
    ret = 0;

    int zero = N - one;

    if (one) ret += one * DP(one - 1, k - 1), ret %= mod;
    if (zero) ret += zero * DP(one + 1, k - 1), ret %= mod;

    return ret;
}

void solve() {
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a) cnt++;
    }

    cout << DP(cnt, K) << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1, tc = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << tc++ << ": ";
        solve();
    }
    return 0;
}