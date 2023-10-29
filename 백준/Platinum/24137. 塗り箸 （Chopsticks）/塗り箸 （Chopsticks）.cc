#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
string S;
int dp[305][305];

int DP(int l, int r) {
    if (l >= N) return 0;
    if (l == r) return 0;
    int &ret = dp[l][r];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = l + 1; i <= r; i++) {
        if (S[i] == S[l]) ret = min(ret, DP(l, i - 1) + DP(i, r));
        else ret = min(ret, 1 + DP(l, i - 1) + DP(i, r));
    }
    return ret;
}

void solve() {
    cin >> N >> S;
    memset(dp, -1, sizeof(dp));
    cout << 1 + DP(0, N - 1);
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