#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int arr[15][15];
int dp[15][(1 << 15)];

int DP(int now, int state) {
    if (state == (1 << 12) - 1) return 0;
    int &ret = dp[now][state];
    if (ret != -1) return ret;
    ret = INF;

    if (now == 13) {
        for (int i = 0; i < 12; i++) {
            ret = min(ret, DP(i, state | (1 << i)));
        }
    } else {
        int mate = (now / 2) * 2 + ((now % 2) ^ 1);
        if (state & (1 << mate)) {
            for (int i = 0; i < 12; i++) {
                if (state & (1 << i)) continue;
                ret = min(ret, arr[now][i] + DP(i, state | (1 << i)));
            }
        } else {
            ret = arr[now][mate] + DP(mate, state | (1 << mate));
        }
    }

    return ret;
}

void solve() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) cin >> arr[i][j];
    }

    memset(dp, -1, sizeof(dp));
    cout << DP(13, 0);

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