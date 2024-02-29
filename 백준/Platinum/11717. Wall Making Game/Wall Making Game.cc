#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H, W;
string arr[25];
int dp[25][25][25][25];

int DP(int x1, int y1, int x2, int y2) {
    if (x1 >= W || x1 < 0 || y1 >= H || y1 < 0 || x2 >= W || x2 < 0 || y2 >= H || y2 < 0) return 0;
    if (x2 < x1 || y2 < y1) return 0;
    int &ret = dp[x1][y1][x2][y2];
    if (ret != -1) return ret;
    
    ret = 0;
    
    set<int> s;
    int now = 0;
    
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            if (arr[i][j] == 'X') continue;
            int a = DP(x1, y1, j - 1, i - 1);
            int b = DP(x1, i + 1, j - 1, y2);
            int c = DP(j + 1, y1, x2, i - 1);
            int d = DP(j + 1, i + 1, x2, y2);
            s.insert((a ^ b ^ c ^ d));
        }
    }
    
    for (int i: s) {
        if (i == now) now++;
        else break;
    }
    
    return ret = now;
}

void solve() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) cin >> arr[i];
    
    memset(dp, -1, sizeof(dp));
    int ans = DP(0, 0, W - 1, H - 1);
    
    if (ans) cout << "First";
    else cout << "Second";
    
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