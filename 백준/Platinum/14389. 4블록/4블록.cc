#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string arr[15];
int dp[15][25][(1 << 11)];

int DP(int y, int x, int state) {
    if (x == M) return 0;
    int &ret = dp[y][x][state];
    if (ret != -1) return ret;
    ret = 0;

    int next = (state << 1) & ((1 << (N + 1)) - 1);

    if (arr[y][x] == '1') {
        ret = 1 + DP((y + 1) % N, x + (y + 1) / N, next | 1);
    } else {
        ret = DP((y + 1) % N, x + (y + 1) / N, next);
        ret = max(ret, 1 + DP((y + 1) % N, x + (y + 1) / N, next | 1));
        if (y > 0 && x > 0 && !(state & (1 << 0)) && !(state & (1 << (N - 1))) && !(state & (1 << N))) {
            ret = max(ret, 16 + DP((y + 1) % N, x + (y + 1) / N, next + (1 << 0) + (1 << 1) + (1 << N)));
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << DP(0, 0, 0);

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