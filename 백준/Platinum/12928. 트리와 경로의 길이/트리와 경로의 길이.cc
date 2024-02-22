#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S;
int dp[55][1005];

int DP(int n, int s) {
    if (s > S) return 0;
    if (n == 0) return (s == S);
    int &ret = dp[n][s];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i <= n; i++) ret |= DP(n - i, s + i + i * (i - 1) / 2);
    return ret;
}

void solve() {
    cin >> N >> S;

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 1; i <= N - 1; i++) ans |= DP(N - 1 - i, i * (i - 1) / 2);
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