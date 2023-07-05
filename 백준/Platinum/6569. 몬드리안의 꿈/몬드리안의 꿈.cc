#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H, W;
ll table[15][15][(1 << 15)];

void init();

ll DP(int x, int y, int state);

void solve() {
    init();
    cout << DP(0, 0, 0) << '\n';
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
    while (1) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;
        solve();
    }
    return 0;
}

void init() {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < (1 << (W + 1)); k++) {
                table[i][j][k] = -1;
            }
        }
    }
    return;
}

ll DP(int x, int y, int state) {
    if (y == H) return 1;
    ll &ret = table[x][y][state];
    if (ret != -1) return ret;
    ret = 0;
    if (state & 1) ret += DP((x + 1) % W, y + (x + 1) / W, state >> 1);
    else {
        if ((x != W - 1) && ((state & 2) == 0)) ret += DP((x + 1) % W, y + (x + 1) / W, (state | 2) >> 1);
        if ((y != H - 1) && ((state & (1 << W)) == 0)) ret += DP((x + 1) % W, y + (x + 1) / W, (state | (1 << W)) >> 1);
    }

    return ret;
}