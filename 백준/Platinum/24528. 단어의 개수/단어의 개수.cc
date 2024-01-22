#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 998244353;

int N;
pii arr[1000005];
ll dp[1000005][27];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        arr[i].first = (int) (c - 'a');
        cin >> arr[i].second;
    }

    dp[0][26] = 1;
    for (int i = 1; i <= N; i++) {
        ll a = arr[i].first, b = arr[i].second;
        for (int j = 0; j <= 26; j++) {
            if (j != a) dp[i][j] = dp[i - 1][j];
        }

        for (int j = 0; j <= 26; j++) {
            if (j != a) dp[i][a] += (dp[i - 1][j] * b) % mod, dp[i][a] %= mod;
            else dp[i][a] += dp[i - 1][a], dp[i][a] %= mod;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) ans += dp[N][i], ans %= mod;

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