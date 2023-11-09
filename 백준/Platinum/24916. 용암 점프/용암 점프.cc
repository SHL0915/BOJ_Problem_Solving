#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[25];
ll dp[25][25][2][2];

ll DP(int l, int r, int cur, int pre) {
    if (l == 0 && r == N - 1) return 1;
    ll &ret = dp[l][r][cur][pre];
    if (ret != -1) return ret;
    ret = 0;
    
    ll cpos, delt;
    if (cur == 0) {
        cpos = arr[l];
        if (pre == 0) delt = arr[l + 1] - arr[l];
        else delt = arr[r] - arr[l];
    } else {
        cpos = arr[r];
        if (pre == 0) delt = arr[r] - arr[r - 1];
        else delt = arr[r] - arr[l];
    }
    
    if (l == r) delt = 0;
    if (l > 0) {
        if (abs(cpos - arr[l - 1]) >= 2 * delt) {
            if (cur == 0) ret = (ret + DP(l - 1, r, 0, 0));
            else ret = (ret + DP(l - 1, r, 0, 1));
        }
    }
    if (r < N - 1) {
        if (abs(cpos - arr[r + 1]) >= 2 * delt) {
            if (cur == 0) ret = (ret + DP(l, r + 1, 1, 1));
            else ret = (ret + DP(l, r + 1, 1, 0));
        }
    }
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    if (N > 20) {
        cout << 0 << '\n';
        return;
    }
    sort(arr, arr + N);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        if (DP(i, i, 0, 0) == 0) cout << "NO\n";
        else cout << "YES\n";
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
    cin >> t;
    while (t--) solve();
    return 0;
}