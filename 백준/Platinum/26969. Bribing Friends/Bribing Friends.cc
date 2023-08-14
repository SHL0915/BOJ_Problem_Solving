#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct cow {
    int X, P, C;

    bool operator<(const cow cmp) const {
        return X < cmp.X;
    }
};

int N, A, B;
cow arr[2005];
ll dp[2005][2005][2];

ll DP(int idx, int a, int t) {
    if (a < 0) return -INF;
    if (idx == N) return 0;
    ll &ret = dp[idx][a][t];
    if (ret != -1) return ret;
    ret = 0;

    ret = max(ret, DP(idx + 1, a, t));

    if (t == 0) {
        int d = min(arr[idx].C, a / arr[idx].X);
        if (d == arr[idx].C) ret = max(ret, arr[idx].P + DP(idx + 1, a - d * arr[idx].X, t));
        else ret = max(ret, arr[idx].P + DP(idx + 1, A - (arr[idx].C - d), 1));
    } else ret = max(ret, arr[idx].P + DP(idx + 1, a - arr[idx].C, t));

    return ret;
}

void solve() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) cin >> arr[i].P >> arr[i].C >> arr[i].X;
    sort(arr, arr + N);

    memset(dp, -1, sizeof(dp));
    cout << DP(0, B, 0);
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