#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

string S;
ll dp[305][305];

ll DP(int s, int e) {
    if (s > e) return 1;
    if (s == e) return 0;
    if (s + 1 == e) {
        if (S[s] == S[e]) return 0;
        else return 1;
    }
    ll &ret = dp[s][e];
    if (~ret) return ret;
    ret = 0;

    for (int i = s + 1; i <= e; i++) {
        if (S[s] != S[i]) {
            ll now = (DP(s + 1, i - 1) * DP(i + 1, e)) % mod;
            ret += now;
            ret %= mod;
        }
    }

    return ret;
}

void solve() {
    cin >> S;

    memset(dp, -1, sizeof(dp));

    cout << DP(0, S.length() - 1);

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