#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int SZ = 500000;

int N, K, D;
int arr[500005];
int dp[500005];
int seg[1000005];

void update(int pos, int val) {
    pos += SZ;
    seg[pos] = max(seg[pos], val);
    for (; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}

void solve() {
    cin >> N >> K >> D;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int q = query(max(1, arr[i] - D), min(SZ, arr[i] + D));
        int now = max({1, dp[arr[i] % K] + 1, q + 1});

        ans = max(ans, now);
        update(arr[i], now);
        dp[arr[i] % K] = max(dp[arr[i] % K], now);
    }

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